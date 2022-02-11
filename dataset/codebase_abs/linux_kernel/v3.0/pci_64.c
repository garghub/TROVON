static int T_1 F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 ( V_4 L_1 ) ;
V_5 . V_6 = V_7 ;
if ( V_8 )
V_9 |= V_10 ;
V_9 |= V_11 | V_12 ;
F_3 (hose, tmp, &hose_list, list_node) {
F_4 ( V_2 ) ;
F_5 ( V_2 -> V_13 ) ;
}
F_6 () ;
F_2 ( V_14 L_2 ) ;
return 0 ;
}
int F_7 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
F_8 ( V_13 == NULL ) ;
if ( V_13 -> V_16 ) {
#ifdef F_9
struct V_17 * V_18 = V_13 -> V_17 [ 0 ] ;
#endif
F_10 ( L_3 ,
F_11 ( V_13 -> V_16 ) ) ;
#ifdef F_9
F_12 ( & V_19 , V_18 -> V_20 + V_21 ,
V_18 -> V_22 + V_21 + 1 ) ;
#endif
return 0 ;
}
V_2 = F_13 ( V_13 ) ;
if ( V_2 -> V_23 == 0 )
return 0 ;
F_10 ( L_4 , V_2 -> V_24 -> V_25 ) ;
F_10 ( L_5 , V_2 -> V_23 ) ;
F_14 ( V_2 -> V_23 ) ;
return 0 ;
}
int T_2 F_15 ( struct V_15 * V_13 )
{
struct V_26 * V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
unsigned long V_30 ;
struct V_1 * V_2 ;
F_8 ( V_13 == NULL ) ;
if ( V_13 -> V_16 ) {
F_10 ( L_6 ,
F_11 ( V_13 -> V_16 ) ) ;
F_10 ( L_7 ,
V_13 -> V_17 [ 0 ] -> V_20 + V_21 ,
V_13 -> V_17 [ 0 ] -> V_22 + V_21 ) ;
return 0 ;
}
V_2 = F_13 ( V_13 ) ;
V_28 = F_16 ( V_2 -> V_31 , V_32 ) ;
V_29 = F_17 ( V_2 -> V_33 , V_32 ) ;
V_2 -> V_23 = NULL ;
if ( V_2 -> V_33 == 0 || V_2 -> V_31 == 0 )
return 0 ;
V_27 = F_18 ( V_29 , 0 , V_34 , V_35 ) ;
if ( V_27 == NULL )
return - V_36 ;
V_2 -> V_23 = V_27 -> V_37 ;
V_2 -> V_38 = ( void V_39 * ) ( V_27 -> V_37 +
V_2 -> V_31 - V_28 ) ;
F_10 ( L_8 , V_2 -> V_24 -> V_25 ) ;
F_10 ( L_9 ,
V_2 -> V_31 , V_2 -> V_38 , V_2 -> V_23 ) ;
F_10 ( L_10 ,
V_2 -> V_33 , V_29 ) ;
if ( F_19 ( V_28 , V_27 -> V_37 , V_29 ,
V_40 | V_41 ) == NULL )
return - V_36 ;
V_30 = ( unsigned long ) V_2 -> V_38 - V_21 ;
V_2 -> V_42 . V_20 += V_30 ;
V_2 -> V_42 . V_22 += V_30 ;
F_10 ( L_11 , & V_2 -> V_42 ) ;
return 0 ;
}
void T_2 F_20 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_13 ) ;
}
long F_21 ( long V_43 , unsigned long V_44 ,
unsigned long V_45 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_15 * V_13 = NULL ;
struct V_48 * V_49 ;
if ( V_44 == 0 && F_22 ( L_12 ) ) {
struct V_48 * V_50 ;
V_50 = F_23 ( NULL , NULL , L_13 ) ;
if ( V_50 )
V_44 = 0xf0 ;
F_24 ( V_50 ) ;
}
for ( V_47 = V_51 . V_52 ; V_47 != & V_51 ; V_47 = V_47 -> V_52 ) {
V_13 = F_25 ( V_47 ) ;
if ( V_44 >= V_13 -> V_53 && V_44 <= V_13 -> V_54 )
break;
V_13 = NULL ;
}
if ( V_13 == NULL || V_13 -> V_55 . V_56 == NULL )
return - V_57 ;
V_49 = V_13 -> V_55 . V_56 ;
V_2 = F_26 ( V_49 ) -> V_58 ;
switch ( V_43 ) {
case V_59 :
return ( long ) V_2 -> V_60 ;
case V_61 :
return ( long ) V_2 -> V_62 ;
case V_63 :
return ( long ) V_2 -> V_31 ;
case V_64 :
return ( long ) V_65 ;
case V_66 :
return - V_67 ;
}
return - V_68 ;
}
int F_27 ( struct V_15 * V_13 )
{
struct V_1 * V_58 = F_13 ( V_13 ) ;
return V_58 -> V_69 ;
}
