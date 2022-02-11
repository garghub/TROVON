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
F_2 ( V_2 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ) ;
F_5 ( & V_10 -> V_22 ) ;
F_13 (priv, &dev->filelist, lhead) {
struct V_48 * V_49 ;
F_14 () ;
V_49 = F_15 ( V_47 -> V_50 , V_51 ) ;
F_2 ( V_2 , L_28 ,
V_49 ? V_49 -> V_52 : L_29 ,
F_16 ( V_47 -> V_50 ) ,
V_47 -> V_8 -> V_53 ,
V_47 -> V_54 ? 'y' : 'n' ,
V_47 -> V_55 ? 'y' : 'n' ,
F_17 ( F_18 ( V_2 ) , V_47 -> V_56 ) ,
V_47 -> V_57 ) ;
F_19 () ;
}
F_7 ( & V_10 -> V_22 ) ;
return 0 ;
}
static int F_20 ( int V_58 , void * V_59 , void * V_3 )
{
struct V_60 * V_61 = V_59 ;
struct V_1 * V_2 = V_3 ;
F_2 ( V_2 , L_30 ,
V_61 -> V_15 , V_61 -> V_24 ,
V_61 -> V_62 ,
F_10 ( & V_61 -> V_43 . V_43 ) ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_9 * V_10 = V_5 -> V_8 -> V_10 ;
F_2 ( V_2 , L_31 ) ;
F_5 ( & V_10 -> V_63 ) ;
F_22 ( & V_10 -> V_64 , F_20 , V_2 ) ;
F_7 ( & V_10 -> V_63 ) ;
return 0 ;
}
