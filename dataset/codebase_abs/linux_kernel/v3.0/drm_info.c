int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = V_8 -> V_12 ;
const char * V_13 ;
if ( ! V_12 )
return 0 ;
V_13 = V_10 -> V_14 -> V_15 -> V_16 ( V_10 ) ;
if ( V_12 -> V_17 ) {
F_2 ( V_2 , L_1 ,
V_13 ,
F_3 ( V_10 -> V_10 ) , V_12 -> V_17 ) ;
} else {
F_2 ( V_2 , L_2 ,
V_13 , F_3 ( V_10 -> V_10 ) ) ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
const char * V_22 [] = { L_3 , L_4 , L_5 , L_6 , L_7 , L_8 } ;
const char * type ;
int V_23 ;
F_5 ( & V_10 -> V_24 ) ;
F_2 ( V_2 , L_9 ) ;
V_23 = 0 ;
F_6 (r_list, &dev->maplist, head) {
V_19 = V_21 -> V_19 ;
if ( ! V_19 )
continue;
if ( V_19 -> type < 0 || V_19 -> type > 5 )
type = L_10 ;
else
type = V_22 [ V_19 -> type ] ;
F_2 ( V_2 , L_11 ,
V_23 ,
( unsigned long long ) V_19 -> V_25 ,
V_19 -> V_26 , type , V_19 -> V_27 ,
( unsigned long ) V_21 -> V_28 ) ;
if ( V_19 -> V_29 < 0 )
F_2 ( V_2 , L_12 ) ;
else
F_2 ( V_2 , L_13 , V_19 -> V_29 ) ;
V_23 ++ ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
int V_23 ;
struct V_30 * V_31 ;
F_5 ( & V_10 -> V_24 ) ;
F_2 ( V_2 , L_14
L_15
L_16 ) ;
for ( V_23 = 0 ; V_23 < V_10 -> V_32 ; V_23 ++ ) {
V_31 = V_10 -> V_33 [ V_23 ] ;
F_9 ( & V_31 -> V_34 ) ;
F_2 ( V_2 , L_17
L_18 ,
V_23 ,
V_31 -> V_27 ,
F_10 ( & V_31 -> V_34 ) ,
F_10 ( & V_31 -> V_35 ) ,
F_10 ( & V_31 -> V_36 ) ,
F_10 ( & V_31 -> V_37 ) ? 'r' : '-' ,
F_10 ( & V_31 -> V_38 ) ? 'w' : '-' ,
F_11 ( & V_31 -> V_39 ) ? 'r' : '-' ,
F_11 ( & V_31 -> V_40 ) ? 'w' : '-' ,
F_11 ( & V_31 -> V_41 ) ? 'f' : '-' ,
F_12 ( & V_31 -> V_42 ) ) ;
F_13 ( & V_31 -> V_34 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_43 * V_44 ;
int V_23 , V_45 ;
F_5 ( & V_10 -> V_24 ) ;
V_44 = V_10 -> V_44 ;
if ( ! V_44 ) {
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
F_2 ( V_2 , L_19 ) ;
for ( V_23 = 0 ; V_23 <= V_46 ; V_23 ++ ) {
if ( V_44 -> V_47 [ V_23 ] . V_48 ) {
V_45 = V_44 -> V_47 [ V_23 ] . V_49 * ( 1 << V_44 -> V_47 [ V_23 ] . V_50 ) ;
F_2 ( V_2 , L_20 ,
V_23 ,
V_44 -> V_47 [ V_23 ] . V_51 ,
V_44 -> V_47 [ V_23 ] . V_48 ,
F_10 ( & V_44 -> V_47 [ V_23 ] . V_52 . V_53 ) ,
V_44 -> V_47 [ V_23 ] . V_49 ,
V_45 ,
V_45 * V_54 / 1024 ) ;
}
}
F_2 ( V_2 , L_21 ) ;
for ( V_23 = 0 ; V_23 < V_44 -> V_48 ; V_23 ++ ) {
if ( V_23 && ! ( V_23 % 32 ) )
F_2 ( V_2 , L_21 ) ;
F_2 ( V_2 , L_22 , V_44 -> V_55 [ V_23 ] -> V_56 ) ;
}
F_2 ( V_2 , L_21 ) ;
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
int V_57 ;
F_5 ( & V_10 -> V_24 ) ;
for ( V_57 = 0 ; V_57 < V_10 -> V_58 ; V_57 ++ ) {
F_2 ( V_2 , L_23 ,
V_57 , F_10 ( & V_10 -> V_59 [ V_57 ] ) ) ;
F_2 ( V_2 , L_24 ,
V_57 , F_16 ( V_10 , V_57 ) ) ;
F_2 ( V_2 , L_25 ,
V_57 , V_10 -> V_60 [ V_57 ] ) ;
F_2 ( V_2 , L_26 ,
V_57 , V_10 -> V_61 [ V_57 ] ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_62 * V_63 ;
F_5 ( & V_10 -> V_24 ) ;
F_2 ( V_2 , L_27 ) ;
F_6 (priv, &dev->filelist, lhead) {
F_2 ( V_2 , L_28 ,
V_63 -> V_64 ? 'y' : 'n' ,
V_63 -> V_8 -> V_65 ,
V_63 -> V_66 ,
V_63 -> V_67 , V_63 -> V_68 , V_63 -> V_69 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_18 ( int V_70 , void * V_71 , void * V_3 )
{
struct V_72 * V_73 = V_71 ;
struct V_1 * V_2 = V_3 ;
F_2 ( V_2 , L_29 , V_73 -> V_74 , V_73 -> V_26 ) ;
F_2 ( V_2 , L_30 ,
V_73 -> V_74 , V_73 -> V_26 ,
F_10 ( & V_73 -> V_75 ) ,
F_10 ( & V_73 -> V_76 . V_76 ) ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
F_2 ( V_2 , L_31 ) ;
F_20 ( & V_10 -> V_77 , F_18 , V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
#if F_22 ( V_82 )
unsigned int V_83 ;
#endif
F_5 ( & V_10 -> V_24 ) ;
F_2 ( V_2 , L_32 ,
F_10 ( & V_10 -> V_84 ) ,
V_85 , ( void * ) F_23 ( V_85 ) ) ;
F_6 (pt, &dev->vmalist, head) {
V_81 = V_79 -> V_81 ;
if ( ! V_81 )
continue;
F_2 ( V_2 ,
L_33 ,
V_79 -> V_66 ,
( void * ) V_81 -> V_86 , ( void * ) V_81 -> V_87 ,
V_81 -> V_88 & V_89 ? 'r' : '-' ,
V_81 -> V_88 & V_90 ? 'w' : '-' ,
V_81 -> V_88 & V_91 ? 'x' : '-' ,
V_81 -> V_88 & V_92 ? 's' : 'p' ,
V_81 -> V_88 & V_93 ? 'l' : '-' ,
V_81 -> V_88 & V_94 ? 'i' : '-' ,
V_81 -> V_95 ) ;
#if F_22 ( V_82 )
V_83 = F_24 ( V_81 -> V_96 ) ;
F_2 ( V_2 , L_34 ,
V_83 & V_97 ? 'p' : '-' ,
V_83 & V_98 ? 'w' : 'r' ,
V_83 & V_99 ? 'u' : 's' ,
V_83 & V_100 ? 't' : 'b' ,
V_83 & V_101 ? 'u' : 'c' ,
V_83 & V_102 ? 'a' : '-' ,
V_83 & V_103 ? 'd' : '-' ,
V_83 & V_104 ? 'm' : 'k' ,
V_83 & V_105 ? 'g' : 'l' ) ;
#endif
F_2 ( V_2 , L_21 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
