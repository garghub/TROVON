int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
struct V_10 * V_11 = V_3 ;
struct V_12 V_13 = { NULL , 0 } ;
int V_14 = 0 ;
struct V_15 V_16 ;
int V_17 , V_18 ;
int V_19 ;
V_16 . V_20 = V_3 ;
V_16 . V_21 = V_4 ;
V_19 = V_22 | V_23 ;
V_2 -> V_8 -> V_9 -> V_24 = V_25 ;
V_17 = F_2 ( V_2 -> V_8 , & V_13 , & V_16 , 1 ,
sizeof( struct V_10 ) , V_19 ) ;
if ( F_3 ( V_26 ) ) {
V_14 = - V_27 ;
V_7 -> V_28 = V_27 ;
V_2 -> V_9 . V_28 = V_27 ;
goto V_29;
}
if ( V_7 -> V_28 ) {
V_14 = - V_7 -> V_28 ;
V_2 -> V_9 . V_28 = V_7 -> V_28 ;
goto V_29;
}
if ( ! V_17 ) {
V_2 -> V_9 . V_28 = V_30 ;
V_14 = - V_30 ;
goto V_29;
}
if ( V_17 < 0 ) {
V_2 -> V_9 . V_28 = - V_17 ;
V_14 = V_17 ;
goto V_29;
}
V_18 = F_4 ( V_11 -> V_31 ) ;
if ( ( V_17 < sizeof( struct V_10 ) ) ||
( V_18 < sizeof( struct V_32 ) ) ||
( V_18 > sizeof( struct V_33 ) ) ||
memcmp ( V_11 -> V_34 , V_35 , sizeof( V_35 ) ) ||
( ( V_11 -> type != V_36 ) &&
( V_11 -> type != V_5 ) ) ) {
V_2 -> V_9 . V_28 = V_37 ;
V_14 = - V_37 ;
goto V_29;
}
V_16 . V_20 = V_3 ;
V_16 . V_21 = V_4 ;
memset ( & V_13 , 0 , sizeof( struct V_12 ) ) ;
V_19 = V_23 ;
V_2 -> V_8 -> V_9 -> V_24 = V_25 ;
V_17 = F_2 ( V_2 -> V_8 , & V_13 , & V_16 , 1 , V_18 , V_19 ) ;
if ( V_17 < V_18 ) {
V_2 -> V_9 . V_28 = V_37 ;
V_14 = - V_37 ;
goto V_29;
}
if ( V_11 -> type == V_36 ) {
V_14 = V_38 ;
if ( F_5 ( ( (struct V_32 * ) V_3 ) -> V_39 )
== V_40 )
V_2 -> V_41 . V_42 -> V_43 = true ;
}
V_29:
return V_14 ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_44 ,
T_1 V_45 )
{
struct V_32 V_46 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memcpy ( V_46 . V_47 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_46 . V_47 . type = V_36 ;
V_46 . V_47 . V_31 = F_7 ( sizeof( struct V_32 ) ) ;
V_46 . V_47 . V_48 = V_49 ;
V_46 . V_47 . V_50 = V_45 ? 1 : 0 ;
memcpy ( V_46 . V_51 , V_52 , sizeof( V_52 ) ) ;
V_46 . V_39 = F_8 ( V_44 ) ;
memcpy ( V_46 . V_53 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_46 ;
V_16 . V_21 = sizeof( struct V_32 ) ;
V_17 = F_9 ( V_2 -> V_8 , & V_13 , & V_16 , 1 ,
sizeof( struct V_32 ) ) ;
if ( V_17 < sizeof( struct V_32 ) )
V_2 -> V_9 . V_28 = V_37 ;
if ( V_17 < 0 )
V_2 -> V_9 . V_28 = - V_17 ;
return V_17 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_57 V_58 ;
int V_14 = 0 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 , V_59 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
memcpy ( V_58 . V_47 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_58 . V_47 . type = V_60 ;
V_58 . V_47 . V_31 = F_7 ( sizeof( V_58 ) ) ;
V_58 . V_47 . V_48 = V_49 ;
memcpy ( V_58 . V_61 . V_51 , V_52 , sizeof( V_52 ) ) ;
memcpy ( & V_58 . V_61 . V_62 , & V_55 -> V_62 [ V_56 - 1 ] , V_63 ) ;
memcpy ( & V_58 . V_61 . V_64 , & V_55 -> V_64 [ V_56 - 1 ] , V_65 ) ;
V_59 = F_11 ( V_2 -> V_8 , & V_58 . V_66 ,
& V_58 . V_67 ) ;
if ( V_59 )
return V_68 ;
memcpy ( V_58 . V_53 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_58 ;
V_16 . V_21 = sizeof( V_58 ) ;
V_17 = F_9 ( V_2 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_58 ) ) ;
if ( V_17 < sizeof( V_58 ) ) {
if ( V_17 >= 0 ) {
V_14 = - V_69 ;
V_2 -> V_9 . V_28 = - V_14 ;
} else {
V_2 -> V_9 . V_28 = V_2 -> V_8 -> V_9 -> V_28 ;
V_14 = - V_2 -> V_9 . V_28 ;
}
}
return V_14 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_70 * V_41 = & V_2 -> V_41 ;
struct V_33 V_71 ;
struct V_72 * V_73 ;
int V_14 = 0 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 ;
V_73 = & V_41 -> V_42 -> V_74 [ V_75 ] ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
memcpy ( V_71 . V_47 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_71 . V_47 . type = V_76 ;
V_71 . V_47 . V_31 = F_7 ( sizeof( V_71 ) ) ;
V_71 . V_47 . V_48 = V_49 ;
memcpy ( V_71 . V_61 . V_51 , V_52 , sizeof( V_52 ) ) ;
memcpy ( & V_71 . V_61 . V_62 , & V_73 -> V_55 -> V_62 [ V_73 -> V_56 - 1 ] ,
V_63 ) ;
memcpy ( & V_71 . V_61 . V_64 , & V_73 -> V_55 -> V_64 [ V_73 -> V_56 - 1 ] , V_65 ) ;
F_13 ( V_71 . V_77 , V_73 -> V_78 -> V_79 ) ;
V_71 . V_80 =
F_8 ( V_41 -> V_81 -> V_82 [ V_75 ] ) ;
V_71 . V_83 = 1 ;
V_71 . V_84 = F_8 ( V_41 -> V_85 ) ;
V_71 . V_86 = F_14 ( V_73 -> V_87 , V_73 -> V_88 ) ;
V_71 . V_89 = V_41 -> V_90 ;
V_71 . V_91 =
F_15 ( ( V_92 ) V_41 -> V_81 -> V_93 [ V_75 ] ) ;
F_13 ( V_71 . V_94 , V_73 -> V_95 ) ;
memcpy ( V_71 . V_53 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_71 ;
V_16 . V_21 = sizeof( V_71 ) ;
V_17 = F_9 ( V_2 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_71 ) ) ;
if ( V_17 < sizeof( V_71 ) ) {
if ( V_17 >= 0 ) {
V_14 = - V_69 ;
V_2 -> V_9 . V_28 = - V_14 ;
} else {
V_2 -> V_9 . V_28 = V_2 -> V_8 -> V_9 -> V_28 ;
V_14 = - V_2 -> V_9 . V_28 ;
}
}
return V_14 ;
}
int F_16 ( struct V_1 * V_96 , int V_97 )
{
struct V_70 * V_41 = & V_96 -> V_41 ;
struct V_33 V_98 ;
struct V_72 * V_73 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_59 = 0 ;
int V_17 ;
V_73 = & V_41 -> V_42 -> V_74 [ V_75 ] ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
memcpy ( V_98 . V_47 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_98 . V_47 . type = V_99 ;
V_98 . V_47 . V_31 = F_7 ( sizeof( V_98 ) ) ;
V_98 . V_47 . V_48 = V_49 ;
if ( V_97 )
V_98 . V_47 . V_50 = 1 ;
memcpy ( V_98 . V_61 . V_51 , V_52 , sizeof( V_52 ) ) ;
memcpy ( & V_98 . V_61 . V_62 , & V_73 -> V_55 -> V_62 [ V_73 -> V_56 - 1 ] ,
V_63 ) ;
memcpy ( & V_98 . V_61 . V_64 , V_73 -> V_55 -> V_64 [ V_73 -> V_56 - 1 ] , V_65 ) ;
F_13 ( V_98 . V_77 , V_73 -> V_78 -> V_79 ) ;
V_98 . V_80 =
F_8 ( V_41 -> V_81 -> V_82 [ V_75 ] ) ;
V_98 . V_83 = 1 ;
V_98 . V_84 = F_8 ( V_41 -> V_85 ) ;
V_98 . V_86 = V_73 -> V_87 ;
V_98 . V_89 = V_41 -> V_90 ,
V_98 . V_91 =
F_15 ( ( V_92 ) V_41 -> V_81 -> V_93 [ V_75 ] ) ;
F_13 ( V_98 . V_94 , V_73 -> V_95 ) ;
memcpy ( V_98 . V_53 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_98 ;
V_16 . V_21 = sizeof( V_98 ) ;
V_17 = F_9 ( V_96 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_98 ) ) ;
if ( V_17 < sizeof( V_98 ) ) {
if ( V_17 >= 0 )
V_96 -> V_9 . V_28 = V_37 ;
else
V_96 -> V_9 . V_28 = V_96 -> V_8 -> V_9 -> V_28 ;
V_59 = F_17 ( & V_96 -> V_9 ) ;
}
return V_59 ;
}
