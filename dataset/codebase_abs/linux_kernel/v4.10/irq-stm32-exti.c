static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 -> V_6 [ 0 ] ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_9 ;
int V_10 ;
F_4 ( V_8 , V_2 ) ;
while ( ( V_9 = F_5 ( V_6 , V_11 ) ) ) {
F_6 (n, &pending, BITS_PER_LONG) {
F_7 ( F_8 ( V_4 , V_10 ) ) ;
F_9 ( V_6 , F_10 ( V_10 ) , V_11 ) ;
}
}
F_11 ( V_8 , V_2 ) ;
}
static int F_12 ( struct V_12 * V_13 , unsigned int type )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
int V_14 = V_13 -> V_15 ;
T_1 V_16 , V_17 ;
F_14 ( V_6 ) ;
V_16 = F_5 ( V_6 , V_18 ) ;
V_17 = F_5 ( V_6 , V_19 ) ;
switch ( type ) {
case V_20 :
V_16 |= F_10 ( V_14 ) ;
V_17 &= ~ F_10 ( V_14 ) ;
break;
case V_21 :
V_16 &= ~ F_10 ( V_14 ) ;
V_17 |= F_10 ( V_14 ) ;
break;
case V_22 :
V_16 |= F_10 ( V_14 ) ;
V_17 |= F_10 ( V_14 ) ;
break;
default:
F_15 ( V_6 ) ;
return - V_23 ;
}
F_9 ( V_6 , V_16 , V_18 ) ;
F_9 ( V_6 , V_17 , V_19 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , unsigned int V_24 )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
int V_14 = V_13 -> V_15 ;
T_1 V_25 ;
F_14 ( V_6 ) ;
V_25 = F_5 ( V_6 , V_26 ) ;
if ( V_24 )
V_25 |= F_10 ( V_14 ) ;
else
V_25 &= ~ F_10 ( V_14 ) ;
F_9 ( V_6 , V_25 , V_26 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_27 , unsigned int V_28 ,
unsigned int V_29 , void * V_13 )
{
struct V_5 * V_6 = V_27 -> V_6 -> V_6 [ 0 ] ;
struct V_30 * V_31 = V_13 ;
T_2 V_15 ;
V_15 = V_31 -> V_32 [ 0 ] ;
F_18 ( V_27 , V_28 , V_15 ) ;
F_19 ( V_27 , V_28 , V_15 , & V_6 -> V_33 -> V_8 , V_6 ,
V_34 , NULL , NULL ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_27 , unsigned int V_28 ,
unsigned int V_29 )
{
struct V_12 * V_13 = F_21 ( V_27 , V_28 ) ;
F_22 ( V_13 ) ;
}
static int T_3 F_23 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
unsigned int V_38 = V_39 | V_40 | V_41 ;
int V_29 , V_42 , V_43 , V_44 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
void * V_45 ;
V_45 = F_24 ( V_36 , 0 ) ;
if ( ! V_45 ) {
F_25 ( L_1 , V_36 -> V_46 ) ;
return - V_47 ;
}
F_26 ( ~ 0UL , V_45 + V_18 ) ;
V_42 = F_27 ( F_28 ( V_45 + V_18 ) ) ;
F_26 ( 0 , V_45 + V_18 ) ;
F_29 ( L_2 , V_36 -> V_46 , V_42 ) ;
V_4 = F_30 ( V_36 , V_42 ,
& V_48 , NULL ) ;
if ( ! V_4 ) {
F_25 ( L_3 ,
V_36 -> V_49 ) ;
V_43 = - V_47 ;
goto V_50;
}
V_43 = F_31 ( V_4 , V_42 , 1 , L_4 ,
V_51 , V_38 , 0 , 0 ) ;
if ( V_43 ) {
F_25 ( L_5 ,
V_36 -> V_46 ) ;
goto V_52;
}
V_6 = V_4 -> V_6 -> V_6 [ 0 ] ;
V_6 -> V_53 = V_45 ;
V_6 -> V_33 -> type = V_22 ;
V_6 -> V_33 -> V_8 . V_49 = V_6 -> V_33 [ 0 ] . V_8 . V_49 ;
V_6 -> V_33 -> V_8 . V_54 = V_55 ;
V_6 -> V_33 -> V_8 . V_56 = V_57 ;
V_6 -> V_33 -> V_8 . V_58 = V_59 ;
V_6 -> V_33 -> V_8 . V_60 = F_12 ;
V_6 -> V_33 -> V_8 . V_61 = F_16 ;
V_6 -> V_33 -> V_62 . V_63 = V_11 ;
V_6 -> V_33 -> V_62 . V_64 = V_65 ;
V_6 -> V_33 -> V_66 = V_51 ;
V_29 = F_32 ( V_36 ) ;
for ( V_44 = 0 ; V_44 < V_29 ; V_44 ++ ) {
unsigned int V_67 = F_33 ( V_36 , V_44 ) ;
F_34 ( V_67 , V_4 ) ;
F_35 ( V_67 , F_1 ) ;
}
return 0 ;
V_52:
F_36 ( V_4 ) ;
V_50:
F_37 ( V_45 ) ;
return V_43 ;
}
