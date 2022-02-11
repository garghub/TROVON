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
if ( ( (struct V_32 * ) V_3 ) -> V_39 . V_40 ) {
V_2 -> V_41 . V_42 -> V_43 = true ;
F_5 ( V_2 -> V_41 . V_42 ) ;
}
}
V_29:
return V_14 ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_32 V_45 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memcpy ( V_45 . V_39 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_45 . V_39 . type = V_36 ;
V_45 . V_39 . V_31 = F_7 ( sizeof( struct V_32 ) ) ;
V_45 . V_39 . V_46 = V_47 ;
V_45 . V_39 . V_40 = ( V_44 == V_48 ) ? 1 : 0 ;
memcpy ( V_45 . V_49 , V_50 , sizeof( V_50 ) ) ;
V_45 . V_51 = F_8 ( V_44 ) ;
memcpy ( V_45 . V_52 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_45 ;
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
struct V_53 * V_54 ,
T_1 V_55 )
{
struct V_56 V_57 ;
int V_14 = 0 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 , V_58 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
memcpy ( V_57 . V_39 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_57 . V_39 . type = V_59 ;
V_57 . V_39 . V_31 = F_7 ( sizeof( V_57 ) ) ;
V_57 . V_39 . V_46 = V_47 ;
memcpy ( V_57 . V_60 . V_49 , V_50 , sizeof( V_50 ) ) ;
memcpy ( & V_57 . V_60 . V_61 , & V_54 -> V_61 [ V_55 - 1 ] , V_62 ) ;
memcpy ( & V_57 . V_60 . V_63 , & V_54 -> V_63 [ V_55 - 1 ] , V_64 ) ;
V_58 = F_11 ( V_2 -> V_8 , & V_57 . V_65 ,
& V_57 . V_66 ) ;
if ( V_58 )
return V_67 ;
memcpy ( V_57 . V_52 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_57 ;
V_16 . V_21 = sizeof( V_57 ) ;
V_17 = F_9 ( V_2 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_57 ) ) ;
if ( V_17 < sizeof( V_57 ) ) {
if ( V_17 >= 0 ) {
V_14 = - V_68 ;
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
struct V_69 * V_41 = & V_2 -> V_41 ;
struct V_33 V_70 ;
struct V_71 * V_72 ;
int V_14 = 0 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_17 ;
V_72 = & V_41 -> V_42 -> V_73 [ V_74 ] ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
memcpy ( V_70 . V_39 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_70 . V_39 . type = V_75 ;
V_70 . V_39 . V_31 = F_7 ( sizeof( V_70 ) ) ;
V_70 . V_39 . V_46 = V_47 ;
memcpy ( V_70 . V_60 . V_49 , V_50 , sizeof( V_50 ) ) ;
memcpy ( & V_70 . V_60 . V_61 , & V_72 -> V_54 -> V_61 [ V_72 -> V_55 - 1 ] ,
V_62 ) ;
memcpy ( & V_70 . V_60 . V_63 , & V_72 -> V_54 -> V_63 [ V_72 -> V_55 - 1 ] , V_64 ) ;
F_13 ( V_70 . V_76 , V_72 -> V_77 -> V_78 ) ;
V_70 . V_79 =
F_8 ( V_41 -> V_80 -> V_81 [ V_74 ] -> V_82 ) ;
V_70 . V_83 = 1 ;
V_70 . V_84 = F_8 ( V_41 -> V_85 ) ;
V_70 . V_86 = F_14 ( V_72 -> V_87 , V_72 -> V_88 ) ;
V_70 . V_89 = V_41 -> V_90 ;
V_70 . V_91 = F_15 (
( V_92 ) F_16 ( V_41 -> V_80 -> V_93 [ V_74 ] . V_94 ) ) ;
F_13 ( V_70 . V_95 , V_72 -> V_96 ) ;
memcpy ( V_70 . V_52 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_70 ;
V_16 . V_21 = sizeof( V_70 ) ;
V_17 = F_9 ( V_2 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_70 ) ) ;
if ( V_17 < sizeof( V_70 ) ) {
if ( V_17 >= 0 ) {
V_14 = - V_68 ;
V_2 -> V_9 . V_28 = - V_14 ;
} else {
V_2 -> V_9 . V_28 = V_2 -> V_8 -> V_9 -> V_28 ;
V_14 = - V_2 -> V_9 . V_28 ;
}
}
return V_14 ;
}
int F_17 ( struct V_1 * V_97 , int V_98 )
{
struct V_69 * V_41 = & V_97 -> V_41 ;
struct V_33 V_99 ;
struct V_71 * V_72 ;
struct V_12 V_13 ;
struct V_15 V_16 ;
int V_58 = 0 ;
int V_17 ;
V_72 = & V_41 -> V_42 -> V_73 [ V_74 ] ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
memcpy ( V_99 . V_39 . V_34 , V_35 , sizeof( V_35 ) ) ;
V_99 . V_39 . type = V_100 ;
V_99 . V_39 . V_31 = F_7 ( sizeof( V_99 ) ) ;
V_99 . V_39 . V_46 = V_47 ;
if ( V_98 )
V_99 . V_39 . V_40 = 1 ;
memcpy ( V_99 . V_60 . V_49 , V_50 , sizeof( V_50 ) ) ;
memcpy ( & V_99 . V_60 . V_61 , & V_72 -> V_54 -> V_61 [ V_72 -> V_55 - 1 ] ,
V_62 ) ;
memcpy ( & V_99 . V_60 . V_63 , V_72 -> V_54 -> V_63 [ V_72 -> V_55 - 1 ] , V_64 ) ;
F_13 ( V_99 . V_76 , V_72 -> V_77 -> V_78 ) ;
V_99 . V_79 =
F_8 ( V_41 -> V_80 -> V_81 [ V_74 ] -> V_82 ) ;
V_99 . V_83 = 1 ;
V_99 . V_84 = F_8 ( V_41 -> V_85 ) ;
V_99 . V_86 = V_72 -> V_87 ;
V_99 . V_89 = V_41 -> V_90 ,
V_99 . V_91 = F_15 (
( V_92 ) F_16 ( V_41 -> V_80 -> V_93 [ V_74 ] . V_94 ) ) ;
F_13 ( V_99 . V_95 , V_72 -> V_96 ) ;
memcpy ( V_99 . V_52 . V_34 , V_35 , sizeof( V_35 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_16 . V_20 = & V_99 ;
V_16 . V_21 = sizeof( V_99 ) ;
V_17 = F_9 ( V_97 -> V_8 , & V_13 , & V_16 , 1 , sizeof( V_99 ) ) ;
if ( V_17 < sizeof( V_99 ) ) {
if ( V_17 >= 0 )
V_97 -> V_9 . V_28 = V_37 ;
else
V_97 -> V_9 . V_28 = V_97 -> V_8 -> V_9 -> V_28 ;
V_58 = F_18 ( & V_97 -> V_9 ) ;
}
return V_58 ;
}
