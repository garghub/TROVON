static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned int V_7 = V_4 -> V_8 -> V_7 ;
unsigned int V_9 ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 < V_7 )
return V_7 - V_9 - 1 ;
F_3 ( V_4 -> V_5 , L_1 ) ;
return - V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_15 )
return 0 ;
switch ( V_14 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return 0 ;
default:
return - V_10 ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned int V_27 ;
int V_9 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return;
F_6 ( V_4 -> V_28 , F_7 ( V_9 , 4 ) , & V_27 ) ;
V_27 &= ~ V_29 ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 4 ) , V_27 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_11 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_12 -> V_14 ;
struct V_30 * V_31 ;
unsigned int V_32 = V_33 , V_34 ;
int V_9 ;
if ( ! V_14 )
return;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return;
V_31 = F_10 ( V_14 , 0 ) ;
switch ( V_14 -> V_16 ) {
case V_17 :
V_34 = V_35 ;
break;
case V_18 :
V_34 = V_36 ;
break;
case V_20 :
V_32 = V_37 ;
case V_19 :
V_34 = V_38 ;
break;
case V_22 :
V_32 = V_37 ;
case V_21 :
V_34 = V_39 ;
break;
case V_24 :
V_32 = V_37 ;
case V_23 :
V_34 = V_40 ;
break;
case V_25 :
V_34 = V_41 ;
break;
default:
return;
}
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 1 ) ,
F_11 ( V_12 -> V_42 ) |
F_12 ( V_12 -> V_43 ) ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 2 ) ,
F_13 ( V_12 -> V_44 ) |
F_14 ( V_12 -> V_45 ) ) ;
F_8 ( V_4 -> V_28 ,
F_7 ( V_9 , 3 ) , V_31 -> V_46 ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 4 ) ,
V_29 |
F_15 ( 0xff ) |
F_16 ( V_34 ) |
V_32 ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 5 ) ,
F_17 ( 0xFF ) |
F_18 ( 0xFF ) |
F_19 ( 0xFF ) ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 6 ) ,
F_20 ( 0 ) |
F_21 ( 0 ) |
F_22 ( 0 ) ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 7 ) , 0 ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 8 ) ,
F_23 ( 0 ) ) ;
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 9 ) ,
F_24 ( 0 ) ) ;
if ( ! strcmp ( V_4 -> V_8 -> V_47 , L_2 ) ) {
F_8 ( V_4 -> V_28 , F_7 ( V_9 , 10 ) ,
F_25 ( 0 ) |
F_26 ( 0 ) ) ;
}
F_27 ( V_4 -> V_28 , V_48 ,
V_49 ,
F_28 ( V_50 ) ) ;
F_8 ( V_4 -> V_28 ,
V_51 , V_52 ) ;
return;
}
static void
F_29 ( struct V_1 * V_2 ,
const struct V_11 * V_53 )
{
}
static int
F_30 ( struct V_1 * V_2 ,
const struct V_11 * V_53 )
{
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
}
void F_34 ( struct V_54 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_55 , V_56 ;
for ( V_55 = 0 ; V_55 < V_4 -> V_8 -> V_7 ; V_55 ++ ) {
for ( V_56 = 1 ; V_56 <= V_4 -> V_8 -> V_57 ; V_56 ++ )
F_8 ( V_4 -> V_28 , F_7 ( V_55 , V_56 ) , 0 ) ;
}
F_27 ( V_4 -> V_28 , V_48 ,
V_49 ,
F_28 ( V_58 ) ) ;
F_8 ( V_4 -> V_28 , V_51 ,
V_52 ) ;
}
struct V_1 * F_35 ( struct V_54 * V_5 )
{
struct V_1 * V_59 ;
int V_60 ;
V_59 = F_36 ( sizeof( * V_59 ) , V_61 ) ;
if ( ! V_59 ) {
F_37 ( L_3 ) ;
return NULL ;
}
V_60 = F_38 ( V_5 , V_59 , 0 ,
& V_62 ,
V_63 ,
F_39 ( V_63 ) ,
V_64 , NULL ) ;
if ( V_60 ) {
F_33 ( V_59 ) ;
V_59 = NULL ;
}
F_40 ( V_59 , & V_65 ) ;
return V_59 ;
}
