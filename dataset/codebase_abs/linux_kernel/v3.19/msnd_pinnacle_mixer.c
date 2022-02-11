static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_5 [ 3 ] = {
L_1 , L_2 , L_3 ,
} ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = F_3 ( V_9 , & V_7 -> V_10 ) ? 3 : 2 ;
return F_4 ( V_4 , 1 , V_8 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_12 -> V_13 . V_14 . V_15 [ 0 ] = 0 ;
if ( V_7 -> V_16 & V_17 ) {
V_12 -> V_13 . V_14 . V_15 [ 0 ] = 1 ;
} else if ( ( V_7 -> V_16 & V_18 ) &&
F_3 ( V_9 , & V_7 -> V_10 ) ) {
V_12 -> V_13 . V_14 . V_15 [ 0 ] = 2 ;
}
return 0 ;
}
static int F_6 ( struct V_6 * V_7 , int V_19 )
{
unsigned V_20 ;
int V_21 ;
unsigned char V_22 ;
switch ( V_19 ) {
case 0 :
V_20 = V_23 ;
V_22 = V_24 ;
break;
case 1 :
V_20 = V_17 ;
V_22 = V_25 ;
break;
case 2 :
V_20 = V_18 ;
V_22 = V_26 ;
break;
default:
return - V_27 ;
}
V_21 = V_20 != V_7 -> V_16 ;
if ( V_21 ) {
V_21 = 0 ;
if ( ! F_7 ( V_7 , 0 , 0 , V_22 ) )
if ( ! F_8 ( V_7 , V_28 ) ) {
V_7 -> V_16 = V_20 ;
V_21 = 1 ;
}
}
return V_21 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_6 * V_29 = F_2 ( V_2 ) ;
return F_6 ( V_29 , V_12 -> V_13 . V_14 . V_15 [ 0 ] ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_30 ;
V_4 -> V_31 = 2 ;
V_4 -> V_13 . integer . V_32 = 0 ;
V_4 -> V_13 . integer . V_33 = 100 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_6 * V_29 = F_2 ( V_2 ) ;
int V_34 = V_2 -> V_35 ;
unsigned long V_10 ;
F_12 ( & V_29 -> V_36 , V_10 ) ;
V_12 -> V_13 . integer . V_13 [ 0 ] = V_29 -> V_37 [ V_34 ] * 100 ;
V_12 -> V_13 . integer . V_13 [ 0 ] /= 0xFFFF ;
V_12 -> V_13 . integer . V_13 [ 1 ] = V_29 -> V_38 [ V_34 ] * 100 ;
V_12 -> V_13 . integer . V_13 [ 1 ] /= 0xFFFF ;
F_13 ( & V_29 -> V_36 , V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_39 , int V_40 , int V_41 , int V_42 )
{
int V_43 , V_44 ;
int V_45 , V_46 ;
int V_47 = 0 ;
if ( V_40 >= V_48 )
return - V_27 ;
V_43 = V_41 * 0xff / 100 ;
V_45 = V_41 * 0xffff / 100 ;
V_44 = V_42 * 0xff / 100 ;
V_46 = V_42 * 0xffff / 100 ;
V_39 -> V_37 [ V_40 ] = V_45 ;
V_39 -> V_38 [ V_40 ] = V_46 ;
switch ( V_40 ) {
case V_49 :
F_15 ( V_43 , V_39 -> V_50 + V_51 ) ;
F_15 ( V_44 , V_39 -> V_50 + V_52 ) ;
if ( F_7 ( V_39 , 0 , 0 , V_53 ) == 0 )
F_8 ( V_39 , V_28 ) ;
break;
case V_54 :
if ( V_39 -> type == V_55 )
return - V_27 ;
F_15 ( V_43 , V_39 -> V_50 + V_56 ) ;
F_15 ( V_44 , V_39 -> V_50 + V_57 ) ;
if ( F_7 ( V_39 , 0 , 0 , V_58 ) == 0 )
F_8 ( V_39 , V_28 ) ;
break;
case V_59 :
F_16 ( V_45 , V_39 -> V_50 + V_60 ) ;
F_16 ( V_46 , V_39 -> V_50 + V_61 ) ;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_47 = 1 ;
break;
default:
return - V_27 ;
}
if ( V_47 ) {
F_17 ( V_64 , V_66 ) ;
F_17 ( V_65 , V_67 ) ;
if ( V_39 -> type == V_68 )
F_17 ( V_63 , V_69 ) ;
F_18 ( V_62 , V_70 , V_71 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_6 * V_29 = F_2 ( V_2 ) ;
int V_21 , V_34 = V_2 -> V_35 ;
int V_41 , V_42 ;
unsigned long V_10 ;
V_41 = V_12 -> V_13 . integer . V_13 [ 0 ] % 101 ;
V_42 = V_12 -> V_13 . integer . V_13 [ 1 ] % 101 ;
F_12 ( & V_29 -> V_36 , V_10 ) ;
V_21 = V_29 -> V_37 [ V_34 ] != V_41
|| V_29 -> V_38 [ V_34 ] != V_42 ;
F_14 ( V_29 , V_34 , V_41 , V_42 ) ;
F_13 ( & V_29 -> V_36 , V_10 ) ;
return V_21 ;
}
int F_20 ( struct V_72 * V_73 )
{
struct V_6 * V_7 = V_73 -> V_74 ;
unsigned int V_75 ;
int V_76 ;
if ( F_21 ( ! V_7 ) )
return - V_27 ;
F_22 ( & V_7 -> V_36 ) ;
strcpy ( V_73 -> V_77 , L_4 ) ;
for ( V_75 = 0 ; V_75 < F_23 ( V_78 ) ; V_75 ++ )
V_76 = F_24 ( V_73 ,
F_25 ( V_78 + V_75 , V_7 ) ) ;
if ( V_76 < 0 )
return V_76 ;
return 0 ;
}
void F_26 ( struct V_6 * V_39 )
{
F_27 ( V_49 , V_79 , V_53 ) ;
F_18 ( V_62 , V_70 , V_71 ) ;
F_17 ( V_64 , V_66 ) ;
F_17 ( V_65 , V_67 ) ;
if ( V_39 -> type == V_68 ) {
F_27 ( V_54 , V_80 , V_58 ) ;
F_17 ( V_63 , V_69 ) ;
}
}
int F_28 ( struct V_6 * V_39 , int V_16 )
{
V_39 -> V_16 = - 1 ;
return F_6 ( V_39 , V_16 ) ;
}
