bool F_1 ( struct V_1 * V_1 )\r\n{\r\nif ( V_1 -> V_2 . V_3 == 1 )\r\nreturn true ;\r\nif ( ( V_1 -> V_2 . V_3 == 2 ) &&\r\n( ! F_2 ( V_1 ) -> V_4 ) )\r\nreturn true ;\r\nreturn false ;\r\n}
