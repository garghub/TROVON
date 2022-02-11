int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = V_8 -> V_12 ;
if ( ! V_12 )
return 0 ;
if ( V_12 -> V_13 ) {
F_2 ( V_2 , L_1 ,
V_10 -> V_14 -> V_15 ,
F_3 ( V_10 -> V_10 ) , V_12 -> V_13 ) ;
} else {
F_2 ( V_2 , L_2 ,
V_10 -> V_14 -> V_15 , F_3 ( V_10 -> V_10 ) ) ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
const char * V_20 [] = { L_3 , L_4 , L_5 , L_6 , L_7 , L_8 } ;
const char * type ;
int V_21 ;
F_5 ( & V_10 -> V_22 ) ;
F_2 ( V_2 , L_9 ) ;
V_21 = 0 ;
F_6 (r_list, &dev->maplist, head) {
V_17 = V_19 -> V_17 ;
if ( ! V_17 )
continue;
if ( V_17 -> type < 0 || V_17 -> type > 5 )
type = L_10 ;
else
type = V_20 [ V_17 -> type ] ;
F_2 ( V_2 , L_11 ,
V_21 ,
( unsigned long long ) V_17 -> V_23 ,
V_17 -> V_24 , type , V_17 -> V_25 ,
( unsigned long ) V_19 -> V_26 ) ;
if ( V_17 -> V_27 < 0 )
F_2 ( V_2 , L_12 ) ;
else
F_2 ( V_2 , L_13 , V_17 -> V_27 ) ;
V_21 ++ ;
}
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_28 * V_29 ;
int V_21 , V_30 ;
F_5 ( & V_10 -> V_22 ) ;
V_29 = V_10 -> V_29 ;
if ( ! V_29 ) {
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
F_2 ( V_2 , L_14 ) ;
for ( V_21 = 0 ; V_21 <= V_31 ; V_21 ++ ) {
if ( V_29 -> V_32 [ V_21 ] . V_33 ) {
V_30 = V_29 -> V_32 [ V_21 ] . V_34 * ( 1 << V_29 -> V_32 [ V_21 ] . V_35 ) ;
F_2 ( V_2 , L_15 ,
V_21 ,
V_29 -> V_32 [ V_21 ] . V_36 ,
V_29 -> V_32 [ V_21 ] . V_33 ,
0 ,
V_29 -> V_32 [ V_21 ] . V_34 ,
V_30 ,
V_30 * V_37 / 1024 ) ;
}
}
F_2 ( V_2 , L_16 ) ;
for ( V_21 = 0 ; V_21 < V_29 -> V_33 ; V_21 ++ ) {
if ( V_21 && ! ( V_21 % 32 ) )
F_2 ( V_2 , L_16 ) ;
F_2 ( V_2 , L_17 , V_29 -> V_38 [ V_21 ] -> V_39 ) ;
}
F_2 ( V_2 , L_16 ) ;
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
int V_40 ;
F_5 ( & V_10 -> V_22 ) ;
for ( V_40 = 0 ; V_40 < V_10 -> V_41 ; V_40 ++ ) {
F_2 ( V_2 , L_18 ,
V_40 , F_10 ( & V_10 -> V_42 [ V_40 ] . V_43 ) ) ;
F_2 ( V_2 , L_19 ,
V_40 , F_11 ( V_10 , V_40 ) ) ;
F_2 ( V_2 , L_20 ,
V_40 , V_10 -> V_42 [ V_40 ] . V_44 ) ;
F_2 ( V_2 , L_21 ,
V_40 , V_10 -> V_42 [ V_40 ] . V_45 ) ;
}
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_46 * V_47 ;
F_5 ( & V_10 -> V_22 ) ;
F_2 ( V_2 , L_22 ) ;
F_6 (priv, &dev->filelist, lhead) {
F_2 ( V_2 , L_23 ,
V_47 -> V_48 ? 'y' : 'n' ,
V_47 -> V_8 -> V_49 ,
F_13 ( V_47 -> V_50 ) ,
F_14 ( F_15 ( V_2 ) , V_47 -> V_51 ) ,
V_47 -> V_52 ) ;
}
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
static int F_16 ( int V_53 , void * V_54 , void * V_3 )
{
struct V_55 * V_56 = V_54 ;
struct V_1 * V_2 = V_3 ;
F_2 ( V_2 , L_24 ,
V_56 -> V_15 , V_56 -> V_24 ,
V_56 -> V_57 ,
F_10 ( & V_56 -> V_43 . V_43 ) ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
F_2 ( V_2 , L_25 ) ;
F_5 ( & V_10 -> V_58 ) ;
F_18 ( & V_10 -> V_59 , F_16 , V_2 ) ;
F_7 ( & V_10 -> V_58 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
unsigned long V_64 = 0 ;
#if F_20 ( V_65 )
unsigned int V_66 ;
#endif
F_5 ( & V_10 -> V_22 ) ;
F_6 (pt, &dev->vmalist, head)
V_64 ++ ;
F_2 ( V_2 , L_26 ,
V_64 , V_67 ,
( void * ) ( unsigned long ) F_21 ( V_67 ) ) ;
F_6 (pt, &dev->vmalist, head) {
V_63 = V_61 -> V_63 ;
if ( ! V_63 )
continue;
F_2 ( V_2 ,
L_27 ,
V_61 -> V_50 ,
( void * ) V_63 -> V_68 , ( void * ) V_63 -> V_69 ,
V_63 -> V_70 & V_71 ? 'r' : '-' ,
V_63 -> V_70 & V_72 ? 'w' : '-' ,
V_63 -> V_70 & V_73 ? 'x' : '-' ,
V_63 -> V_70 & V_74 ? 's' : 'p' ,
V_63 -> V_70 & V_75 ? 'l' : '-' ,
V_63 -> V_70 & V_76 ? 'i' : '-' ,
V_63 -> V_77 ) ;
#if F_20 ( V_65 )
V_66 = F_22 ( V_63 -> V_78 ) ;
F_2 ( V_2 , L_28 ,
V_66 & V_79 ? 'p' : '-' ,
V_66 & V_80 ? 'w' : 'r' ,
V_66 & V_81 ? 'u' : 's' ,
V_66 & V_82 ? 't' : 'b' ,
V_66 & V_83 ? 'u' : 'c' ,
V_66 & V_84 ? 'a' : '-' ,
V_66 & V_85 ? 'd' : '-' ,
V_66 & V_86 ? 'm' : 'k' ,
V_66 & V_87 ? 'g' : 'l' ) ;
#endif
F_2 ( V_2 , L_16 ) ;
}
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
