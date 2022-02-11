static int T_1 F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 ( V_4 L_1 ) ;
V_5 . V_6 = V_7 ;
if ( V_8 )
F_3 ( V_9 ) ;
F_3 ( V_10 | V_11 ) ;
F_4 (hose, tmp, &hose_list, list_node) {
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_12 ) ;
}
F_7 () ;
F_2 ( V_13 L_2 ) ;
return 0 ;
}
int F_8 ( struct V_14 * V_12 )
{
struct V_1 * V_2 ;
F_9 ( V_12 == NULL ) ;
if ( V_12 -> V_15 ) {
#ifdef F_10
struct V_16 * V_17 = V_12 -> V_16 [ 0 ] ;
#endif
F_11 ( L_3 ,
F_12 ( V_12 -> V_15 ) ) ;
#ifdef F_10
F_13 ( & V_18 , V_17 -> V_19 + V_20 ,
V_17 -> V_21 + V_20 + 1 ) ;
#endif
return 0 ;
}
V_2 = F_14 ( V_12 ) ;
if ( V_2 -> V_22 == 0 )
return 0 ;
F_11 ( L_4 , V_2 -> V_23 -> V_24 ) ;
F_11 ( L_5 , V_2 -> V_22 ) ;
F_15 ( V_2 -> V_22 ) ;
return 0 ;
}
int T_2 F_16 ( struct V_14 * V_12 )
{
struct V_25 * V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
struct V_1 * V_2 ;
F_9 ( V_12 == NULL ) ;
if ( V_12 -> V_15 ) {
F_11 ( L_6 ,
F_12 ( V_12 -> V_15 ) ) ;
F_11 ( L_7 ,
V_12 -> V_16 [ 0 ] -> V_19 + V_20 ,
V_12 -> V_16 [ 0 ] -> V_21 + V_20 ) ;
return 0 ;
}
V_2 = F_14 ( V_12 ) ;
V_27 = F_17 ( V_2 -> V_30 , V_31 ) ;
V_28 = F_18 ( V_2 -> V_32 , V_31 ) ;
V_2 -> V_22 = NULL ;
if ( V_2 -> V_32 == 0 || V_2 -> V_30 == 0 )
return 0 ;
V_26 = F_19 ( V_28 , 0 , V_33 , V_34 ) ;
if ( V_26 == NULL )
return - V_35 ;
V_2 -> V_22 = V_26 -> V_36 ;
V_2 -> V_37 = ( void V_38 * ) ( V_26 -> V_36 +
V_2 -> V_30 - V_27 ) ;
F_11 ( L_8 , V_2 -> V_23 -> V_24 ) ;
F_11 ( L_9 ,
V_2 -> V_30 , V_2 -> V_37 , V_2 -> V_22 ) ;
F_11 ( L_10 ,
V_2 -> V_32 , V_28 ) ;
if ( F_20 ( V_27 , V_26 -> V_36 , V_28 ,
V_39 | V_40 ) == NULL )
return - V_35 ;
V_29 = ( unsigned long ) V_2 -> V_37 - V_20 ;
V_2 -> V_41 . V_19 += V_29 ;
V_2 -> V_41 . V_21 += V_29 ;
F_11 ( L_11 , & V_2 -> V_41 ) ;
return 0 ;
}
void T_2 F_21 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_12 ) ;
}
long F_22 ( long V_42 , unsigned long V_43 ,
unsigned long V_44 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_14 * V_12 = NULL ;
struct V_47 * V_48 ;
if ( V_43 == 0 && F_23 ( L_12 ) ) {
struct V_47 * V_49 ;
V_49 = F_24 ( NULL , NULL , L_13 ) ;
if ( V_49 )
V_43 = 0xf0 ;
F_25 ( V_49 ) ;
}
for ( V_46 = V_50 . V_51 ; V_46 != & V_50 ; V_46 = V_46 -> V_51 ) {
V_12 = F_26 ( V_46 ) ;
if ( V_43 >= V_12 -> V_52 && V_43 <= V_12 -> V_53 )
break;
V_12 = NULL ;
}
if ( V_12 == NULL || V_12 -> V_54 . V_55 == NULL )
return - V_56 ;
V_48 = V_12 -> V_54 . V_55 ;
V_2 = F_27 ( V_48 ) -> V_57 ;
switch ( V_42 ) {
case V_58 :
return ( long ) V_2 -> V_59 ;
case V_60 :
return ( long ) V_2 -> V_61 ;
case V_62 :
return ( long ) V_2 -> V_30 ;
case V_63 :
return ( long ) V_64 ;
case V_65 :
return - V_66 ;
}
return - V_67 ;
}
int F_28 ( struct V_14 * V_12 )
{
struct V_1 * V_57 = F_14 ( V_12 ) ;
return V_57 -> V_68 ;
}
