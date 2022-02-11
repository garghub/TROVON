bool F_1 ( struct V_1 * V_1 )\r\n{\r\nif ( 1 == V_1 -> V_2 . V_3 )\r\nreturn true ;\r\nif ( ( 2 == V_1 -> V_2 . V_3 ) && ( ! F_2 ( V_1 ) -> V_4 ) )\r\nreturn true ;\r\nreturn false ;\r\n}
