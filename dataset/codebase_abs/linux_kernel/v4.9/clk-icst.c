static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_2 -> V_8 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_9 == V_10 ) {
V_4 -> V_11 = V_5 & V_12 ;
V_4 -> V_13 = 22 ;
V_4 -> V_14 = 1 ;
return 0 ;
}
if ( V_2 -> V_9 == V_15 ) {
V_4 -> V_11 = V_5 & V_16 ;
V_4 -> V_13 = 46 ;
V_4 -> V_14 = 3 ;
return 0 ;
}
if ( V_2 -> V_9 == V_17 ) {
bool V_18 = ! ! ( V_5 & V_19 ) ;
V_4 -> V_11 = V_18 ? 17 : 14 ;
V_4 -> V_13 = V_18 ? 22 : 14 ;
V_4 -> V_14 = 1 ;
return 0 ;
}
if ( V_2 -> V_9 == V_20 ) {
V_4 -> V_11 = V_5 & 0xFF ;
V_4 -> V_13 = 22 ;
V_4 -> V_14 = ( V_5 >> 8 ) & 7 ;
return 0 ;
}
if ( V_2 -> V_9 == V_21 ) {
V_4 -> V_11 = ( V_5 >> 12 ) & 0xFF ;
V_4 -> V_13 = 22 ;
V_4 -> V_14 = ( V_5 >> 20 ) & 7 ;
return 0 ;
}
V_4 -> V_11 = V_5 & 0x1ff ;
V_4 -> V_13 = ( V_5 >> 9 ) & 0x7f ;
V_4 -> V_14 = ( V_5 >> 16 ) & 03 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 V_4 )
{
T_1 V_22 ;
T_1 V_5 ;
int V_6 ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_22 = V_12 ;
V_5 = V_4 . V_11 & 0xFF ;
if ( V_4 . V_11 & 0x100 )
F_4 ( L_1 ) ;
if ( V_4 . V_14 != 1 )
F_4 ( L_2 ) ;
if ( V_4 . V_13 != 22 )
F_4 ( L_3 ) ;
break;
case V_15 :
V_22 = V_16 ;
V_5 = V_4 . V_11 & 0xFF ;
if ( V_4 . V_11 & 0x100 )
F_4 ( L_1 ) ;
if ( V_4 . V_14 != 3 )
F_4 ( L_2 ) ;
if ( V_4 . V_13 != 46 )
F_4 ( L_3 ) ;
break;
case V_20 :
V_22 = V_23 ;
V_5 = ( V_4 . V_11 & 0xFF ) | V_4 . V_14 << 8 ;
if ( V_4 . V_11 & 0x100 )
F_4 ( L_1 ) ;
if ( V_4 . V_13 != 22 )
F_4 ( L_3 ) ;
break;
case V_21 :
V_22 = V_24 ;
V_5 = ( ( V_4 . V_11 & 0xFF ) << 12 ) | ( V_4 . V_14 << 20 ) ;
if ( V_4 . V_11 & 0x100 )
F_4 ( L_1 ) ;
if ( V_4 . V_13 != 22 )
F_4 ( L_3 ) ;
break;
default:
V_22 = V_25 ;
V_5 = V_4 . V_11 | ( V_4 . V_13 << 9 ) | ( V_4 . V_14 << 16 ) ;
break;
}
F_5 ( L_4 , V_5 ) ;
V_6 = F_6 ( V_2 -> V_7 , V_2 -> V_26 , V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_2 -> V_7 , V_2 -> V_8 , V_22 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_2 -> V_7 , V_2 -> V_26 , 0 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static unsigned long F_8 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
struct V_1 * V_2 = F_9 ( V_29 ) ;
struct V_3 V_4 ;
int V_6 ;
if ( V_30 )
V_2 -> V_31 -> V_32 = V_30 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 ) {
F_4 ( L_5 ) ;
return 0 ;
}
V_2 -> V_33 = F_10 ( V_2 -> V_31 , V_4 ) ;
return V_2 -> V_33 ;
}
static long F_11 ( struct V_28 * V_29 , unsigned long V_33 ,
unsigned long * V_34 )
{
struct V_1 * V_2 = F_9 ( V_29 ) ;
struct V_3 V_4 ;
if ( V_2 -> V_9 == V_10 ||
V_2 -> V_9 == V_20 ) {
if ( V_33 <= 12000000 )
return 12000000 ;
if ( V_33 >= 160000000 )
return 160000000 ;
return F_12 ( V_33 , 1000000 ) * 1000000 ;
}
if ( V_2 -> V_9 == V_21 ) {
if ( V_33 <= 6000000 )
return 6000000 ;
if ( V_33 >= 66000000 )
return 66000000 ;
return F_12 ( V_33 , 500000 ) * 500000 ;
}
if ( V_2 -> V_9 == V_15 ) {
if ( V_33 <= 3000000 )
return 3000000 ;
if ( V_33 >= 50000000 )
return 5000000 ;
return F_12 ( V_33 , 250000 ) * 250000 ;
}
if ( V_2 -> V_9 == V_17 ) {
if ( V_33 <= 25000000 || V_33 < 29000000 )
return 25000000 ;
return 33000000 ;
}
V_4 = F_13 ( V_2 -> V_31 , V_33 ) ;
return F_10 ( V_2 -> V_31 , V_4 ) ;
}
static int F_14 ( struct V_28 * V_29 , unsigned long V_33 ,
unsigned long V_30 )
{
struct V_1 * V_2 = F_9 ( V_29 ) ;
struct V_3 V_4 ;
if ( V_2 -> V_9 == V_17 ) {
unsigned int V_5 ;
int V_6 ;
if ( V_33 == 25000000 ) {
V_5 = 0 ;
} else if ( V_33 == 33000000 ) {
V_5 = V_19 ;
} else {
F_4 ( L_6 ,
V_33 ) ;
return - V_35 ;
}
V_6 = F_6 ( V_2 -> V_7 , V_2 -> V_26 ,
V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_2 -> V_7 , V_2 -> V_8 ,
V_19 ,
V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_2 -> V_7 , V_2 -> V_26 , 0 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
if ( V_30 )
V_2 -> V_31 -> V_32 = V_30 ;
V_4 = F_13 ( V_2 -> V_31 , V_33 ) ;
V_2 -> V_33 = F_10 ( V_2 -> V_31 , V_4 ) ;
return F_3 ( V_2 , V_4 ) ;
}
static struct V_36 * F_15 ( struct V_37 * V_38 ,
const struct V_39 * V_40 ,
const char * V_41 ,
const char * V_42 ,
struct V_43 * V_7 ,
enum V_44 V_9 )
{
struct V_36 * V_36 ;
struct V_1 * V_2 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_2 ) {
F_4 ( L_7 ) ;
return F_17 ( - V_50 ) ;
}
V_48 = F_18 ( V_40 -> V_31 , sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 ) {
F_19 ( V_2 ) ;
F_4 ( L_8 ) ;
return F_17 ( - V_50 ) ;
}
V_46 . V_41 = V_41 ;
V_46 . V_51 = & V_52 ;
V_46 . V_53 = 0 ;
V_46 . V_54 = ( V_42 ? & V_42 : NULL ) ;
V_46 . V_55 = ( V_42 ? 1 : 0 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_29 . V_46 = & V_46 ;
V_2 -> V_31 = V_48 ;
V_2 -> V_8 = V_40 -> V_56 ;
V_2 -> V_26 = V_40 -> V_57 ;
V_2 -> V_9 = V_9 ;
V_36 = F_20 ( V_38 , & V_2 -> V_29 ) ;
if ( F_21 ( V_36 ) ) {
F_19 ( V_48 ) ;
F_19 ( V_2 ) ;
}
return V_36 ;
}
struct V_36 * F_22 ( struct V_37 * V_38 ,
const struct V_39 * V_40 ,
const char * V_41 ,
const char * V_42 ,
void T_2 * V_58 )
{
struct V_59 V_60 = {
. V_61 = 32 ,
. V_62 = 32 ,
. V_63 = 4 ,
} ;
struct V_43 * V_7 ;
V_7 = F_23 ( V_38 , V_58 , & V_60 ) ;
if ( F_21 ( V_7 ) ) {
F_4 ( L_9 ) ;
return F_24 ( V_7 ) ;
}
return F_15 ( V_38 , V_40 , V_41 , V_42 , V_7 ,
V_64 ) ;
}
static void T_3 F_25 ( struct V_65 * V_66 )
{
struct V_65 * V_67 ;
struct V_43 * V_7 ;
struct V_39 V_68 ;
const char * V_41 = V_66 -> V_41 ;
const char * V_42 ;
struct V_36 * V_69 ;
enum V_44 V_9 ;
V_67 = F_26 ( V_66 ) ;
if ( ! V_67 ) {
F_4 ( L_10 ) ;
return;
}
V_7 = F_27 ( V_67 ) ;
if ( F_21 ( V_7 ) ) {
F_4 ( L_11 ) ;
return;
}
if ( F_28 ( V_66 , L_12 , & V_68 . V_56 ) ) {
F_4 ( L_13 ) ;
return;
}
if ( F_28 ( V_66 , L_14 , & V_68 . V_57 ) ) {
F_4 ( L_15 ) ;
return;
}
if ( F_29 ( V_66 , L_16 ) ) {
V_68 . V_31 = & V_70 ;
V_9 = V_64 ;
} else if ( F_29 ( V_66 , L_17 ) ) {
V_68 . V_31 = & V_71 ;
V_9 = V_64 ;
} else if ( F_29 ( V_66 , L_18 ) ) {
V_68 . V_31 = & V_72 ;
V_9 = V_10 ;
} else if ( F_29 ( V_66 , L_19 ) ) {
V_68 . V_31 = & V_73 ;
V_9 = V_15 ;
} else if ( F_29 ( V_66 , L_20 ) ) {
V_68 . V_31 = & V_74 ;
V_9 = V_17 ;
} else if ( F_29 ( V_66 , L_21 ) ) {
V_68 . V_31 = & V_72 ;
V_9 = V_20 ;
} else if ( F_29 ( V_66 , L_22 ) ) {
V_68 . V_31 = & V_72 ;
V_9 = V_21 ;
} else {
F_4 ( L_23 , V_41 ) ;
return;
}
V_42 = F_30 ( V_66 , 0 ) ;
V_69 = F_15 ( NULL , & V_68 , V_41 , V_42 , V_7 , V_9 ) ;
if ( F_21 ( V_69 ) ) {
F_4 ( L_24 , V_41 ) ;
return;
}
F_31 ( V_66 , V_75 , V_69 ) ;
F_5 ( L_25 , V_41 ) ;
}
