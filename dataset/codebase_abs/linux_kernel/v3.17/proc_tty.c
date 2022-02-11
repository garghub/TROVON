static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
F_2 ( V_2 , L_1 , V_4 -> V_7 ? V_4 -> V_7 : L_2 ) ;
F_2 ( V_2 , L_3 , V_4 -> V_8 ) ;
if ( V_4 -> V_6 > 1 ) {
F_2 ( V_2 , L_4 , F_3 ( V_5 ) , F_4 ( V_5 ) ,
F_4 ( V_5 ) + V_6 - 1 ) ;
} else {
F_2 ( V_2 , L_5 , F_3 ( V_5 ) , F_4 ( V_5 ) ) ;
}
switch ( V_4 -> type ) {
case V_9 :
F_5 ( V_2 , L_6 ) ;
if ( V_4 -> V_10 == V_11 )
F_5 ( V_2 , L_7 ) ;
else if ( V_4 -> V_10 == V_12 )
F_5 ( V_2 , L_8 ) ;
else if ( V_4 -> V_10 == V_13 )
F_5 ( V_2 , L_9 ) ;
break;
case V_14 :
F_5 ( V_2 , L_10 ) ;
break;
case V_15 :
F_5 ( V_2 , L_11 ) ;
break;
case V_16 :
if ( V_4 -> V_10 == V_17 )
F_5 ( V_2 , L_12 ) ;
else if ( V_4 -> V_10 == V_18 )
F_5 ( V_2 , L_13 ) ;
else
F_5 ( V_2 , L_14 ) ;
break;
default:
F_2 ( V_2 , L_15 , V_4 -> type , V_4 -> V_10 ) ;
}
F_6 ( V_2 , '\n' ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_19 )
{
struct V_3 * V_4 = F_8 ( V_19 , struct V_3 , V_20 ) ;
T_1 V_5 = F_9 ( V_4 -> V_21 , V_4 -> V_22 ) ;
T_1 V_23 = V_5 + V_4 -> V_6 ;
if ( & V_4 -> V_20 == V_20 . V_24 ) {
F_2 ( V_2 , L_16 , L_17 , L_18 ) ;
F_2 ( V_2 , L_5 , V_25 , 0 ) ;
F_5 ( V_2 , L_19 ) ;
F_2 ( V_2 , L_16 , L_20 , L_10 ) ;
F_2 ( V_2 , L_5 , V_25 , 1 ) ;
F_5 ( V_2 , L_21 ) ;
#ifdef F_10
F_2 ( V_2 , L_16 , L_22 , L_23 ) ;
F_2 ( V_2 , L_5 , V_25 , 2 ) ;
F_5 ( V_2 , L_24 ) ;
#endif
#ifdef F_11
F_2 ( V_2 , L_16 , L_25 , L_26 ) ;
F_2 ( V_2 , L_5 , V_26 , 0 ) ;
F_5 ( V_2 , L_27 ) ;
#endif
}
while ( F_3 ( V_5 ) < F_3 ( V_23 ) ) {
T_1 V_24 = F_9 ( F_3 ( V_5 ) + 1 , 0 ) ;
F_1 ( V_2 , V_4 , V_5 , V_24 - V_5 ) ;
V_5 = V_24 ;
}
if ( V_5 != V_23 )
F_1 ( V_2 , V_4 , V_5 , V_23 - V_5 ) ;
return 0 ;
}
static void * F_12 ( struct V_1 * V_2 , T_2 * V_27 )
{
F_13 ( & V_28 ) ;
return F_14 ( & V_20 , * V_27 ) ;
}
static void * F_15 ( struct V_1 * V_2 , void * V_19 , T_2 * V_27 )
{
return F_16 ( V_19 , & V_20 , V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_19 )
{
F_18 ( & V_28 ) ;
}
static int F_19 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_20 ( V_30 , & V_31 ) ;
}
void F_21 ( struct V_3 * V_32 )
{
struct V_33 * V_34 ;
if ( ! V_32 -> V_7 || V_32 -> V_35 ||
! V_32 -> V_36 -> V_37 )
return;
V_34 = F_22 ( V_32 -> V_7 , 0 , V_38 ,
V_32 -> V_36 -> V_37 , V_32 ) ;
V_32 -> V_35 = V_34 ;
}
void F_23 ( struct V_3 * V_32 )
{
struct V_33 * V_34 ;
V_34 = V_32 -> V_35 ;
if ( ! V_34 )
return;
F_24 ( V_32 -> V_7 , V_38 ) ;
V_32 -> V_35 = NULL ;
}
void T_3 F_25 ( void )
{
if ( ! F_26 ( L_18 , NULL ) )
return;
F_26 ( L_28 , NULL ) ;
V_38 = F_27 ( L_29 , V_39 | V_40 , NULL ) ;
F_28 ( L_30 , 0 , NULL , & V_41 ) ;
F_28 ( L_31 , 0 , NULL , & V_42 ) ;
}
