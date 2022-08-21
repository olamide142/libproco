from distutils.core import setup, Extension


def main():
    
    author = "Victor Olowofeso"

    setup(name = "fputs",
            version = "0.0.1",
            description = "Python interface for the fputs C lib function",
            author = author,
            author_email = ''.join(list(reversed(list(map(str.lower, author.split(" ")))))) + '@gmail.com',
            ext_modules = [Extension("fputs", ["fputsmodule.c"])]
        )

if __name__ == "__main__":
    main()
