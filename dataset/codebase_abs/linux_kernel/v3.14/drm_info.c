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
struct V_30 * V_31 ;
int V_23 , V_32 ;
F_5 ( & V_10 -> V_24 ) ;
V_31 = V_10 -> V_31 ;
if ( ! V_31 ) {
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
F_2 ( V_2 , L_14 ) ;
for ( V_23 = 0 ; V_23 <= V_33 ; V_23 ++ ) {
if ( V_31 -> V_34 [ V_23 ] . V_35 ) {
V_32 = V_31 -> V_34 [ V_23 ] . V_36 * ( 1 << V_31 -> V_34 [ V_23 ] . V_37 ) ;
F_2 ( V_2 , L_15 ,
V_23 ,
V_31 -> V_34 [ V_23 ] . V_38 ,
V_31 -> V_34 [ V_23 ] . V_35 ,
F_9 ( & V_31 -> V_34 [ V_23 ] . V_39 . V_40 ) ,
V_31 -> V_34 [ V_23 ] . V_36 ,
V_32 ,
V_32 * V_41 / 1024 ) ;
}
}
F_2 ( V_2 , L_16 ) ;
for ( V_23 = 0 ; V_23 < V_31 -> V_35 ; V_23 ++ ) {
if ( V_23 && ! ( V_23 % 32 ) )
F_2 ( V_2 , L_16 ) ;
F_2 ( V_2 , L_17 , V_31 -> V_42 [ V_23 ] -> V_43 ) ;
}
F_2 ( V_2 , L_16 ) ;
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
int V_44 ;
F_5 ( & V_10 -> V_24 ) ;
for ( V_44 = 0 ; V_44 < V_10 -> V_45 ; V_44 ++ ) {
F_2 ( V_2 , L_18 ,
V_44 , F_9 ( & V_10 -> V_46 [ V_44 ] . V_47 ) ) ;
F_2 ( V_2 , L_19 ,
V_44 , F_11 ( V_10 , V_44 ) ) ;
F_2 ( V_2 , L_20 ,
V_44 , V_10 -> V_46 [ V_44 ] . V_48 ) ;
F_2 ( V_2 , L_21 ,
V_44 , V_10 -> V_46 [ V_44 ] . V_49 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_50 * V_51 ;
F_5 ( & V_10 -> V_24 ) ;
F_2 ( V_2 , L_22 ) ;
F_6 (priv, &dev->filelist, lhead) {
F_2 ( V_2 , L_23 ,
V_51 -> V_52 ? 'y' : 'n' ,
V_51 -> V_8 -> V_53 ,
F_13 ( V_51 -> V_54 ) ,
F_14 ( F_15 ( V_2 ) , V_51 -> V_55 ) ,
V_51 -> V_56 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
static int F_16 ( int V_57 , void * V_58 , void * V_3 )
{
struct V_59 * V_60 = V_58 ;
struct V_1 * V_2 = V_3 ;
F_2 ( V_2 , L_24 ,
V_60 -> V_61 , V_60 -> V_26 ,
V_60 -> V_62 ,
F_9 ( & V_60 -> V_47 . V_47 ) ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
F_2 ( V_2 , L_25 ) ;
F_5 ( & V_10 -> V_63 ) ;
F_18 ( & V_10 -> V_64 , F_16 , V_2 ) ;
F_7 ( & V_10 -> V_63 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
unsigned long V_69 = 0 ;
#if F_20 ( V_70 )
unsigned int V_71 ;
#endif
F_5 ( & V_10 -> V_24 ) ;
F_6 (pt, &dev->vmalist, head)
V_69 ++ ;
F_2 ( V_2 , L_26 ,
V_69 , V_72 ,
( void * ) ( unsigned long ) F_21 ( V_72 ) ) ;
F_6 (pt, &dev->vmalist, head) {
V_68 = V_66 -> V_68 ;
if ( ! V_68 )
continue;
F_2 ( V_2 ,
L_27 ,
V_66 -> V_54 ,
( void * ) V_68 -> V_73 , ( void * ) V_68 -> V_74 ,
V_68 -> V_75 & V_76 ? 'r' : '-' ,
V_68 -> V_75 & V_77 ? 'w' : '-' ,
V_68 -> V_75 & V_78 ? 'x' : '-' ,
V_68 -> V_75 & V_79 ? 's' : 'p' ,
V_68 -> V_75 & V_80 ? 'l' : '-' ,
V_68 -> V_75 & V_81 ? 'i' : '-' ,
V_68 -> V_82 ) ;
#if F_20 ( V_70 )
V_71 = F_22 ( V_68 -> V_83 ) ;
F_2 ( V_2 , L_28 ,
V_71 & V_84 ? 'p' : '-' ,
V_71 & V_85 ? 'w' : 'r' ,
V_71 & V_86 ? 'u' : 's' ,
V_71 & V_87 ? 't' : 'b' ,
V_71 & V_88 ? 'u' : 'c' ,
V_71 & V_89 ? 'a' : '-' ,
V_71 & V_90 ? 'd' : '-' ,
V_71 & V_91 ? 'm' : 'k' ,
V_71 & V_92 ? 'g' : 'l' ) ;
#endif
F_2 ( V_2 , L_16 ) ;
}
F_7 ( & V_10 -> V_24 ) ;
return 0 ;
}
