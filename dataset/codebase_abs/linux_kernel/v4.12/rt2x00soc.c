static void F_1 ( struct V_1 * V_2 )\r\n{\r\nF_2 ( V_2 -> V_3 ) ;\r\nV_2 -> V_3 = NULL ;\r\nF_2 ( V_2 -> V_4 ) ;\r\nV_2 -> V_4 = NULL ;\r\nF_3 ( V_2 -> V_5 . V_6 ) ;\r\n}\r\nstatic int F_4 ( struct V_1 * V_2 )\r\n{\r\nstruct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;\r\nstruct V_10 * V_11 ;\r\nV_11 = F_6 ( V_8 , V_12 , 0 ) ;\r\nif ( ! V_11 )\r\nreturn - V_13 ;\r\nV_2 -> V_5 . V_6 = F_7 ( V_11 -> V_14 , F_8 ( V_11 ) ) ;\r\nif ( ! V_2 -> V_5 . V_6 )\r\nreturn - V_15 ;\r\nV_2 -> V_4 = F_9 ( V_2 -> V_16 -> V_17 , V_18 ) ;\r\nif ( ! V_2 -> V_4 )\r\ngoto exit;\r\nV_2 -> V_3 = F_9 ( V_2 -> V_16 -> V_19 , V_18 ) ;\r\nif ( ! V_2 -> V_3 )\r\ngoto exit;\r\nreturn 0 ;\r\nexit:\r\nF_10 ( L_1 ) ;\r\nF_1 ( V_2 ) ;\r\nreturn - V_15 ;\r\n}\r\nint F_11 ( struct V_7 * V_8 , const struct V_20 * V_16 )\r\n{\r\nstruct V_21 * V_22 ;\r\nstruct V_1 * V_2 ;\r\nint V_23 ;\r\nV_22 = F_12 ( sizeof( struct V_1 ) , V_16 -> V_22 ) ;\r\nif ( ! V_22 ) {\r\nF_10 ( L_2 ) ;\r\nreturn - V_15 ;\r\n}\r\nF_13 ( V_8 , V_22 ) ;\r\nV_2 = V_22 -> V_24 ;\r\nV_2 -> V_9 = & V_8 -> V_9 ;\r\nV_2 -> V_16 = V_16 ;\r\nV_2 -> V_22 = V_22 ;\r\nV_2 -> V_25 = F_14 ( V_8 , 0 ) ;\r\nV_2 -> V_26 = V_8 -> V_9 . V_27 -> V_26 ;\r\nV_2 -> V_28 = F_15 ( & V_8 -> V_9 , NULL ) ;\r\nif ( F_16 ( V_2 -> V_28 ) )\r\nV_2 -> V_28 = NULL ;\r\nF_17 ( V_2 , V_29 ) ;\r\nV_23 = F_4 ( V_2 ) ;\r\nif ( V_23 )\r\ngoto V_30;\r\nV_23 = F_18 ( V_2 ) ;\r\nif ( V_23 )\r\ngoto V_31;\r\nreturn 0 ;\r\nV_31:\r\nF_1 ( V_2 ) ;\r\nV_30:\r\nF_19 ( V_22 ) ;\r\nreturn V_23 ;\r\n}\r\nint F_20 ( struct V_7 * V_8 )\r\n{\r\nstruct V_21 * V_22 = F_21 ( V_8 ) ;\r\nstruct V_1 * V_2 = V_22 -> V_24 ;\r\nF_22 ( V_2 ) ;\r\nF_1 ( V_2 ) ;\r\nF_19 ( V_22 ) ;\r\nreturn 0 ;\r\n}\r\nint F_23 ( struct V_7 * V_8 , T_1 V_32 )\r\n{\r\nstruct V_21 * V_22 = F_21 ( V_8 ) ;\r\nstruct V_1 * V_2 = V_22 -> V_24 ;\r\nreturn F_24 ( V_2 , V_32 ) ;\r\n}\r\nint F_25 ( struct V_7 * V_8 )\r\n{\r\nstruct V_21 * V_22 = F_21 ( V_8 ) ;\r\nstruct V_1 * V_2 = V_22 -> V_24 ;\r\nreturn F_26 ( V_2 ) ;\r\n}
