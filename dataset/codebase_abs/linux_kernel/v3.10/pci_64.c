static int T_1 F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 ( V_4 L_1 ) ;
V_5 . V_6 = V_7 ;
F_3 ( V_8 | V_9 ) ;
F_4 (hose, tmp, &hose_list, list_node) {
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_10 ) ;
}
F_7 () ;
F_2 ( V_11 L_2 ) ;
return 0 ;
}
int F_8 ( struct V_12 * V_10 )
{
struct V_1 * V_2 ;
F_9 ( V_10 == NULL ) ;
if ( V_10 -> V_13 ) {
#ifdef F_10
struct V_14 * V_15 = V_10 -> V_14 [ 0 ] ;
#endif
F_11 ( L_3 ,
F_12 ( V_10 -> V_13 ) ) ;
#ifdef F_10
F_13 ( & V_16 , V_15 -> V_17 + V_18 ,
V_15 -> V_19 + V_18 + 1 ) ;
#endif
return 0 ;
}
V_2 = F_14 ( V_10 ) ;
if ( V_2 -> V_20 == 0 )
return 0 ;
F_11 ( L_4 , V_2 -> V_21 -> V_22 ) ;
F_11 ( L_5 , V_2 -> V_20 ) ;
F_15 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
V_25 = F_17 ( V_2 -> V_28 , V_29 ) ;
V_26 = F_18 ( V_2 -> V_30 , V_29 ) ;
V_2 -> V_20 = NULL ;
if ( V_2 -> V_30 == 0 || V_2 -> V_28 == 0 )
return 0 ;
V_24 = F_19 ( V_26 , 0 , V_31 , V_32 ) ;
if ( V_24 == NULL )
return - V_33 ;
V_2 -> V_20 = V_24 -> V_34 ;
V_2 -> V_35 = ( void V_36 * ) ( V_24 -> V_34 +
V_2 -> V_28 - V_25 ) ;
F_11 ( L_6 , V_2 -> V_21 -> V_22 ) ;
F_11 ( L_7 ,
V_2 -> V_28 , V_2 -> V_35 , V_2 -> V_20 ) ;
F_11 ( L_8 ,
V_2 -> V_30 , V_26 ) ;
if ( F_20 ( V_25 , V_24 -> V_34 , V_26 ,
V_37 | V_38 ) == NULL )
return - V_33 ;
V_27 = F_21 ( V_2 ) ;
V_2 -> V_39 . V_17 += V_27 ;
V_2 -> V_39 . V_19 += V_27 ;
F_11 ( L_9 , & V_2 -> V_39 ) ;
return 0 ;
}
int F_22 ( struct V_12 * V_10 )
{
F_9 ( V_10 == NULL ) ;
if ( V_10 -> V_13 ) {
F_11 ( L_10 ,
F_12 ( V_10 -> V_13 ) ) ;
F_11 ( L_11 ,
V_10 -> V_14 [ 0 ] -> V_17 + V_18 ,
V_10 -> V_14 [ 0 ] -> V_19 + V_18 ) ;
return 0 ;
}
return F_16 ( F_14 ( V_10 ) ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
}
long F_24 ( long V_40 , unsigned long V_41 ,
unsigned long V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_12 * V_10 = NULL ;
struct V_45 * V_46 ;
if ( V_41 == 0 && F_25 ( L_12 ) ) {
struct V_45 * V_47 ;
V_47 = F_26 ( NULL , NULL , L_13 ) ;
if ( V_47 )
V_41 = 0xf0 ;
F_27 ( V_47 ) ;
}
for ( V_44 = V_48 . V_49 ; V_44 != & V_48 ; V_44 = V_44 -> V_49 ) {
V_10 = F_28 ( V_44 ) ;
if ( V_41 >= V_10 -> V_50 && V_41 <= V_10 -> V_51 . V_19 )
break;
V_10 = NULL ;
}
if ( V_10 == NULL || V_10 -> V_52 . V_53 == NULL )
return - V_54 ;
V_46 = V_10 -> V_52 . V_53 ;
V_2 = F_29 ( V_46 ) -> V_55 ;
switch ( V_40 ) {
case V_56 :
return ( long ) V_2 -> V_57 ;
case V_58 :
return ( long ) V_2 -> V_59 [ 0 ] ;
case V_60 :
return ( long ) V_2 -> V_28 ;
case V_61 :
return ( long ) V_62 ;
case V_63 :
return - V_64 ;
}
return - V_65 ;
}
int F_30 ( struct V_12 * V_10 )
{
struct V_1 * V_55 = F_14 ( V_10 ) ;
return V_55 -> V_66 ;
}
static void F_31 ( struct V_67 * V_52 )
{
struct V_68 * V_69 = F_32 ( V_52 ) ;
if ( V_69 )
V_69 -> V_70 = 1 ;
}
