static unsigned long F_1 ( unsigned long V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return ( V_1 >> ( V_2 * 8 ) ) & F_2 ( V_3 * 8 - 1 , 0 ) ;
}
static unsigned long F_3 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 )
{
T_2 V_8 = 0 ;
switch ( V_6 & 0x0c ) {
case V_9 :
if ( V_5 -> V_10 -> V_11 . V_12 . V_13 )
V_8 |= V_14 ;
V_8 |= V_15 | V_16 ;
break;
case V_17 :
V_8 = V_5 -> V_10 -> V_11 . V_12 . V_18 + V_19 ;
V_8 = ( V_8 >> 5 ) - 1 ;
V_8 |= ( V_20 - 1 ) << 19 ;
break;
case V_21 :
V_8 = ( V_22 << 24 ) | ( V_23 << 0 ) ;
break;
default:
return 0 ;
}
return V_8 ;
}
static void F_4 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 ,
unsigned long V_24 )
{
struct V_25 * V_26 = & V_5 -> V_10 -> V_11 . V_12 ;
bool V_27 = V_26 -> V_13 ;
switch ( V_6 & 0x0c ) {
case V_9 :
V_26 -> V_13 = V_24 & V_14 ;
if ( ! V_27 && V_26 -> V_13 )
F_5 ( V_5 -> V_10 ) ;
break;
case V_17 :
case V_21 :
return;
}
}
static unsigned long F_6 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 )
{
int V_28 = F_7 ( V_6 , 64 ) ;
struct V_29 * V_30 = F_8 ( V_5 -> V_10 , NULL , V_28 ) ;
if ( ! V_30 )
return 0 ;
if ( V_6 & 4 )
return 0 ;
return F_1 ( F_9 ( V_30 -> V_31 ) , V_6 & 7 , V_7 ) ;
}
static void F_10 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 ,
unsigned long V_24 )
{
int V_28 = F_7 ( V_6 , 64 ) ;
struct V_29 * V_30 = F_8 ( V_5 -> V_10 , NULL , V_28 ) ;
if ( ! V_30 )
return;
if ( V_6 & 4 )
return;
F_11 ( & V_30 -> V_32 ) ;
V_30 -> V_31 = V_24 & F_12 ( 23 , 0 ) ;
V_30 -> V_33 = F_13 ( V_5 -> V_10 , V_30 -> V_31 ) ;
F_14 ( & V_30 -> V_32 ) ;
}
static unsigned long F_15 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 )
{
unsigned long V_31 = F_16 ( V_5 ) ;
int V_34 = V_5 -> V_35 ;
T_3 V_8 ;
V_8 = ( V_31 & F_12 ( 23 , 0 ) ) << 32 ;
V_8 |= ( ( V_34 & 0xffff ) << 8 ) ;
if ( V_34 == F_17 ( & V_5 -> V_10 -> V_36 ) - 1 )
V_8 |= V_37 ;
return F_1 ( V_8 , V_6 & 7 , V_7 ) ;
}
static unsigned long F_18 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 )
{
return ( V_22 << 24 ) | ( V_23 << 0 ) ;
}
static unsigned long F_19 ( struct V_4 * V_5 ,
T_1 V_6 , unsigned int V_7 )
{
switch ( V_6 & 0xffff ) {
case V_38 :
return 0x3b ;
}
return 0 ;
}
unsigned int F_20 ( struct V_39 * V_40 )
{
V_40 -> V_41 = V_42 ;
V_40 -> V_43 = F_21 ( V_42 ) ;
F_22 ( & V_40 -> V_40 , & V_44 ) ;
return V_45 ;
}
int F_23 ( struct V_10 * V_10 , T_1 V_46 )
{
int V_47 = F_17 ( & V_10 -> V_36 ) ;
struct V_4 * V_5 ;
struct V_39 * V_48 ;
int V_49 , V_50 = 0 ;
V_48 = F_24 ( sizeof( struct V_39 ) * V_47 * 2 ,
V_51 ) ;
if ( ! V_48 )
return - V_52 ;
F_25 (c, vcpu, kvm) {
T_1 V_53 = V_46 + V_49 * V_45 * 2 ;
T_1 V_54 = V_53 + V_45 ;
struct V_39 * V_55 = & V_48 [ V_49 * 2 ] ;
struct V_39 * V_56 = & V_48 [ V_49 * 2 + 1 ] ;
F_22 ( & V_55 -> V_40 , & V_44 ) ;
V_55 -> V_57 = V_53 ;
V_55 -> V_41 = V_58 ;
V_55 -> V_43 = F_21 ( V_58 ) ;
V_55 -> V_59 = V_5 ;
F_26 ( & V_10 -> V_60 ) ;
V_50 = F_27 ( V_10 , V_61 , V_53 ,
V_45 , & V_55 -> V_40 ) ;
F_28 ( & V_10 -> V_60 ) ;
if ( V_50 )
break;
F_22 ( & V_56 -> V_40 , & V_44 ) ;
V_56 -> V_57 = V_54 ;
V_56 -> V_41 = V_62 ;
V_56 -> V_43 = F_21 ( V_62 ) ;
V_56 -> V_59 = V_5 ;
F_26 ( & V_10 -> V_60 ) ;
V_50 = F_27 ( V_10 , V_61 , V_54 ,
V_45 , & V_56 -> V_40 ) ;
F_28 ( & V_10 -> V_60 ) ;
if ( V_50 ) {
F_29 ( V_10 , V_61 ,
& V_55 -> V_40 ) ;
break;
}
}
if ( V_50 ) {
for ( V_49 -- ; V_49 >= 0 ; V_49 -- ) {
F_29 ( V_10 , V_61 ,
& V_48 [ V_49 * 2 ] . V_40 ) ;
F_29 ( V_10 , V_61 ,
& V_48 [ V_49 * 2 + 1 ] . V_40 ) ;
}
F_30 ( V_48 ) ;
} else {
V_10 -> V_11 . V_12 . V_63 = V_48 ;
}
return V_50 ;
}
static int F_31 ( T_3 V_64 , T_4 V_65 , struct V_4 * V_5 )
{
unsigned long V_66 ;
int V_67 ;
V_66 = F_16 ( V_5 ) ;
V_67 = F_32 ( V_66 , 0 ) ;
V_66 &= ~ V_68 ;
if ( V_64 != V_66 )
return - 1 ;
if ( ! ( V_65 & F_33 ( V_67 ) ) )
return - 1 ;
return V_67 ;
}
void F_34 ( struct V_4 * V_5 , T_3 V_69 )
{
struct V_10 * V_10 = V_5 -> V_10 ;
struct V_4 * V_70 ;
T_4 V_71 ;
T_3 V_31 ;
int V_72 , V_49 ;
int V_35 = V_5 -> V_35 ;
bool V_73 ;
V_72 = ( V_69 & V_74 ) >> V_75 ;
V_73 = V_69 & F_33 ( V_76 ) ;
V_71 = ( V_69 & V_77 ) >> V_78 ;
V_31 = F_35 ( V_69 , 3 ) ;
V_31 |= F_35 ( V_69 , 2 ) ;
V_31 |= F_35 ( V_69 , 1 ) ;
F_25 (c, c_vcpu, kvm) {
struct V_29 * V_30 ;
if ( ! V_73 && V_71 == 0 )
break;
if ( V_73 && V_49 == V_35 )
continue;
if ( ! V_73 ) {
int V_67 ;
V_67 = F_31 ( V_31 , V_71 , V_70 ) ;
if ( V_67 == - 1 )
continue;
V_71 &= ~ F_33 ( V_67 ) ;
}
V_30 = F_8 ( V_5 -> V_10 , V_70 , V_72 ) ;
F_11 ( & V_30 -> V_32 ) ;
V_30 -> V_79 = true ;
F_36 ( V_5 -> V_10 , V_30 ) ;
}
}
