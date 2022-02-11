static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_2 ( V_10 ) ;
F_3 ( & V_11 ) ;
F_4 ( & V_12 , & V_10 ) ;
F_5 ( & V_11 ) ;
F_6 (health, n, &tlist, list) {
V_9 = F_7 ( V_4 , struct V_8 , V_4 ) ;
V_7 = F_7 ( V_9 , struct V_6 , V_9 ) ;
F_8 ( V_7 , L_1 ) ;
F_3 ( & V_11 ) ;
F_9 ( & V_4 -> V_13 ) ;
F_5 ( & V_11 ) ;
}
}
static const char * F_10 ( T_1 V_14 )
{
switch ( V_14 ) {
case V_15 :
return L_2 ;
case V_16 :
return L_3 ;
case V_17 :
return L_4 ;
case V_18 :
return L_5 ;
case V_19 :
return L_6 ;
case V_20 :
return L_7 ;
case V_21 :
return L_8 ;
case V_22 :
return L_9 ;
default:
return L_10 ;
}
}
static T_2 F_11 ( T_3 T_4 * V_23 )
{
return F_12 ( F_13 ( ( V_24 T_2 T_4 * ) V_23 ) ) ;
}
static T_5 F_14 ( T_6 T_4 * V_23 )
{
return F_15 ( F_13 ( ( V_24 T_5 T_4 * ) V_23 ) ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = & V_7 -> V_9 . V_4 ;
struct V_25 T_4 * V_26 = V_4 -> V_4 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_17 ( V_26 -> V_28 ) ; V_27 ++ )
F_18 ( L_11 , V_27 , F_14 ( V_26 -> V_28 + V_27 ) ) ;
F_18 ( L_12 , F_14 ( & V_26 -> V_29 ) ) ;
F_18 ( L_13 , F_14 ( & V_26 -> V_30 ) ) ;
F_18 ( L_14 , F_14 ( & V_26 -> V_31 ) ) ;
F_18 ( L_15 , F_14 ( & V_26 -> V_32 ) ) ;
F_18 ( L_16 , F_19 ( & V_26 -> V_33 ) ) ;
F_18 ( L_17 , F_19 ( & V_26 -> V_14 ) , F_10 ( F_19 ( & V_26 -> V_14 ) ) ) ;
F_18 ( L_18 , F_11 ( & V_26 -> V_34 ) ) ;
}
static void F_20 ( unsigned long V_35 )
{
struct V_6 * V_7 = (struct V_6 * ) V_35 ;
struct V_3 * V_4 = & V_7 -> V_9 . V_4 ;
unsigned long V_36 ;
T_5 V_37 ;
V_37 = F_21 ( V_4 -> V_38 ) ;
if ( V_37 == V_4 -> V_39 )
++ V_4 -> V_40 ;
else
V_4 -> V_40 = 0 ;
V_4 -> V_39 = V_37 ;
if ( V_4 -> V_40 == V_41 ) {
F_22 ( V_7 , L_19 ) ;
F_16 ( V_7 ) ;
F_3 ( & V_11 ) ;
F_23 ( & V_4 -> V_13 , & V_12 ) ;
F_5 ( & V_11 ) ;
F_24 ( V_42 , & V_43 ) ;
} else {
F_25 ( & V_36 , sizeof( V_36 ) ) ;
V_36 %= V_44 ;
V_36 += V_45 + V_46 ;
F_26 ( & V_4 -> V_47 , V_36 ) ;
}
}
void F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = & V_7 -> V_9 . V_4 ;
F_28 ( & V_4 -> V_13 ) ;
F_29 ( & V_4 -> V_47 ) ;
V_4 -> V_4 = & V_7 -> V_48 -> V_4 ;
V_4 -> V_38 = & V_7 -> V_48 -> V_38 ;
V_4 -> V_47 . V_35 = ( unsigned long ) V_7 ;
V_4 -> V_47 . V_49 = F_20 ;
V_4 -> V_47 . V_50 = F_30 ( V_45 + V_46 ) ;
F_31 ( & V_4 -> V_47 ) ;
}
void F_32 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = & V_7 -> V_9 . V_4 ;
F_33 ( & V_4 -> V_47 ) ;
F_3 ( & V_11 ) ;
if ( ! F_34 ( & V_4 -> V_13 ) )
F_9 ( & V_4 -> V_13 ) ;
F_5 ( & V_11 ) ;
}
void F_35 ( void )
{
}
void T_7 F_36 ( void )
{
F_37 ( & V_43 , F_1 ) ;
}
