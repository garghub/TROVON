static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static char * V_5 [ 3 ] = {
L_1 , L_2 , L_3 ,
} ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = F_3 ( V_9 , & V_7 -> V_10 ) ? 3 : 2 ;
V_4 -> type = V_11 ;
V_4 -> V_12 = 1 ;
V_4 -> V_13 . V_14 . V_8 = V_8 ;
if ( V_4 -> V_13 . V_14 . V_15 >= V_8 )
V_4 -> V_13 . V_14 . V_15 = V_8 - 1 ;
strcpy ( V_4 -> V_13 . V_14 . V_16 ,
V_5 [ V_4 -> V_13 . V_14 . V_15 ] ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_18 -> V_13 . V_14 . V_15 [ 0 ] = 0 ;
if ( V_7 -> V_19 & V_20 ) {
V_18 -> V_13 . V_14 . V_15 [ 0 ] = 1 ;
} else if ( ( V_7 -> V_19 & V_21 ) &&
F_3 ( V_9 , & V_7 -> V_10 ) ) {
V_18 -> V_13 . V_14 . V_15 [ 0 ] = 2 ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , int V_22 )
{
unsigned V_23 ;
int V_24 ;
unsigned char V_25 ;
switch ( V_22 ) {
case 0 :
V_23 = V_26 ;
V_25 = V_27 ;
break;
case 1 :
V_23 = V_20 ;
V_25 = V_28 ;
break;
case 2 :
V_23 = V_21 ;
V_25 = V_29 ;
break;
default:
return - V_30 ;
}
V_24 = V_23 != V_7 -> V_19 ;
if ( V_24 ) {
V_24 = 0 ;
if ( ! F_6 ( V_7 , 0 , 0 , V_25 ) )
if ( ! F_7 ( V_7 , V_31 ) ) {
V_7 -> V_19 = V_23 ;
V_24 = 1 ;
}
}
return V_24 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_6 * V_32 = F_2 ( V_2 ) ;
return F_5 ( V_32 , V_18 -> V_13 . V_14 . V_15 [ 0 ] ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_33 ;
V_4 -> V_12 = 2 ;
V_4 -> V_13 . integer . V_34 = 0 ;
V_4 -> V_13 . integer . V_35 = 100 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_6 * V_32 = F_2 ( V_2 ) ;
int V_36 = V_2 -> V_37 ;
unsigned long V_10 ;
F_11 ( & V_32 -> V_38 , V_10 ) ;
V_18 -> V_13 . integer . V_13 [ 0 ] = V_32 -> V_39 [ V_36 ] * 100 ;
V_18 -> V_13 . integer . V_13 [ 0 ] /= 0xFFFF ;
V_18 -> V_13 . integer . V_13 [ 1 ] = V_32 -> V_40 [ V_36 ] * 100 ;
V_18 -> V_13 . integer . V_13 [ 1 ] /= 0xFFFF ;
F_12 ( & V_32 -> V_38 , V_10 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_41 , int V_42 , int V_43 , int V_44 )
{
int V_45 , V_46 ;
int V_47 , V_48 ;
int V_49 = 0 ;
if ( V_42 >= V_50 )
return - V_30 ;
V_45 = V_43 * 0xff / 100 ;
V_47 = V_43 * 0xffff / 100 ;
V_46 = V_44 * 0xff / 100 ;
V_48 = V_44 * 0xffff / 100 ;
V_41 -> V_39 [ V_42 ] = V_47 ;
V_41 -> V_40 [ V_42 ] = V_48 ;
switch ( V_42 ) {
case V_51 :
F_14 ( V_45 , V_41 -> V_52 + V_53 ) ;
F_14 ( V_46 , V_41 -> V_52 + V_54 ) ;
if ( F_6 ( V_41 , 0 , 0 , V_55 ) == 0 )
F_7 ( V_41 , V_31 ) ;
break;
case V_56 :
if ( V_41 -> type == V_57 )
return - V_30 ;
F_14 ( V_45 , V_41 -> V_52 + V_58 ) ;
F_14 ( V_46 , V_41 -> V_52 + V_59 ) ;
if ( F_6 ( V_41 , 0 , 0 , V_60 ) == 0 )
F_7 ( V_41 , V_31 ) ;
break;
case V_61 :
F_15 ( V_47 , V_41 -> V_52 + V_62 ) ;
F_15 ( V_48 , V_41 -> V_52 + V_63 ) ;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_49 = 1 ;
break;
default:
return - V_30 ;
}
if ( V_49 ) {
F_16 ( V_66 , V_68 ) ;
F_16 ( V_67 , V_69 ) ;
if ( V_41 -> type == V_70 )
F_16 ( V_65 , V_71 ) ;
F_17 ( V_64 , V_72 , V_73 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_6 * V_32 = F_2 ( V_2 ) ;
int V_24 , V_36 = V_2 -> V_37 ;
int V_43 , V_44 ;
unsigned long V_10 ;
V_43 = V_18 -> V_13 . integer . V_13 [ 0 ] % 101 ;
V_44 = V_18 -> V_13 . integer . V_13 [ 1 ] % 101 ;
F_11 ( & V_32 -> V_38 , V_10 ) ;
V_24 = V_32 -> V_39 [ V_36 ] != V_43
|| V_32 -> V_40 [ V_36 ] != V_44 ;
F_13 ( V_32 , V_36 , V_43 , V_44 ) ;
F_12 ( & V_32 -> V_38 , V_10 ) ;
return V_24 ;
}
int F_19 ( struct V_74 * V_75 )
{
struct V_6 * V_7 = V_75 -> V_76 ;
unsigned int V_77 ;
int V_78 ;
if ( F_20 ( ! V_7 ) )
return - V_30 ;
F_21 ( & V_7 -> V_38 ) ;
strcpy ( V_75 -> V_79 , L_4 ) ;
for ( V_77 = 0 ; V_77 < F_22 ( V_80 ) ; V_77 ++ )
V_78 = F_23 ( V_75 ,
F_24 ( V_80 + V_77 , V_7 ) ) ;
if ( V_78 < 0 )
return V_78 ;
return 0 ;
}
void F_25 ( struct V_6 * V_41 )
{
F_26 ( V_51 , V_81 , V_55 ) ;
F_17 ( V_64 , V_72 , V_73 ) ;
F_16 ( V_66 , V_68 ) ;
F_16 ( V_67 , V_69 ) ;
if ( V_41 -> type == V_70 ) {
F_26 ( V_56 , V_82 , V_60 ) ;
F_16 ( V_65 , V_71 ) ;
}
}
int F_27 ( struct V_6 * V_41 , int V_19 )
{
V_41 -> V_19 = - 1 ;
return F_5 ( V_41 , V_19 ) ;
}
