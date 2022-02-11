static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 > 32 )
return false ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( ! ( ( V_2 -> V_5 [ V_3 ] >= 0x20 ) && ( V_2 -> V_5 [ V_3 ] <= 0x7e ) ) )
return false ;
}
return true ;
}
static T_1 F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 , * V_10 ;
T_1 * V_11 = NULL ;
struct V_12 * V_13 = & ( V_7 -> V_14 ) ;
struct V_15 * V_16 = & ( V_13 -> V_17 ) ;
V_10 = F_3 ( V_16 ) ;
V_9 = F_4 ( V_10 ) ;
V_13 -> V_18 . V_19 = - 2 ;
V_13 -> V_20 |= V_21 ;
V_13 -> V_22 = V_9 ;
V_13 -> V_23 = true ;
if ( ! F_5 ( V_13 , V_24 ) &&
F_6 ( V_16 ) ) {
if ( V_13 -> V_20 & V_21 )
V_13 -> V_20 ^= V_21 ;
if ( V_13 -> V_25 . V_26 == false )
F_7 ( V_7 , & V_13 -> V_27 ) ;
return true ;
} else {
int V_28 ;
V_28 = F_8 ( V_13 ) ;
if ( V_28 == V_29 )
F_9 ( & V_13 -> V_30 , V_31 ) ;
else {
if ( F_5 ( V_13 , V_24 ) ) {
struct V_32 * V_33 =
& ( V_7 -> V_34 . V_35 ) ;
V_13 -> V_20 = V_36 ;
V_11 = V_7 -> V_34 . V_35 .
V_37 ;
memset ( & V_33 -> V_5 , 0 ,
sizeof( struct V_1 ) ) ;
memcpy ( & V_33 -> V_5 ,
& V_13 -> V_27 ,
sizeof( struct V_1 ) ) ;
F_10 ( V_7 ) ;
F_11 ( V_11 ) ;
if ( F_12 ( V_7 ) != V_29 )
return false ;
V_13 -> V_23 = false ;
} else {
if ( V_13 -> V_20 & V_21 )
V_13 -> V_20 ^=
V_21 ;
if ( ! V_13 -> V_25 . V_26 )
F_7 ( V_7 ,
& V_13 -> V_27 ) ;
}
}
}
return true ;
}
T_1 F_13 ( struct V_6 * V_7 , T_1 * V_38 )
{
unsigned long V_39 ;
T_1 V_40 = true ;
struct V_12 * V_13 = & V_7 -> V_14 ;
if ( F_14 ( V_38 ) || F_15 ( V_38 ) ) {
V_40 = false ;
return V_40 ;
}
F_16 ( & V_13 -> V_41 , V_39 ) ;
if ( F_5 ( V_13 , V_42 |
V_21 ) == true ) {
V_40 = F_5 ( V_13 , V_21 ) ;
goto V_43;
}
if ( F_5 ( V_13 ,
V_44 | V_36 ) == true ) {
if ( ! memcmp ( & V_13 -> V_18 . V_45 . V_37 , V_38 ,
V_46 ) ) {
if ( F_5 ( V_13 ,
V_47 ) == false )
goto V_43;
} else {
F_17 ( V_7 ) ;
if ( F_5 ( V_13 , V_44 ) == true )
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
if ( ( F_5 ( V_13 ,
V_36 ) ) ) {
F_20 ( V_13 ,
V_36 ) ;
F_21 ( V_13 , V_24 ) ;
}
}
}
memcpy ( & V_13 -> V_48 , V_38 , V_46 ) ;
V_13 -> V_49 = true ;
V_40 = F_2 ( V_7 ) ;
goto V_50;
V_43:
V_50:
F_22 ( & V_13 -> V_41 , V_39 ) ;
return V_40 ;
}
void F_23 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_51 * V_52 = & V_13 -> V_18 ;
if ( V_7 -> V_53 == false )
return;
F_16 ( & V_13 -> V_41 , V_39 ) ;
if ( F_5 ( V_13 , V_42 | V_21 ) ) {
F_5 ( V_13 , V_21 ) ;
goto V_54;
}
if ( F_5 ( V_13 , V_44 | V_36 ) ) {
if ( ( V_13 -> V_27 . V_4 == V_2 -> V_4 ) &&
( ! memcmp ( & V_13 -> V_27 . V_5 , V_2 -> V_5 ,
V_2 -> V_4 ) ) ) {
if ( ( F_5 ( V_13 ,
V_47 ) == false ) ) {
if ( F_24 ( V_7 ,
V_52 ) == false ) {
F_17 ( V_7 ) ;
if ( F_5 ( V_13 ,
V_44 ) == true )
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
if ( F_5 ( V_13 ,
V_36 ) ) {
F_20 ( V_13 ,
V_36 ) ;
F_21 ( V_13 ,
V_24 ) ;
}
} else
goto V_54;
}
} else {
F_17 ( V_7 ) ;
if ( F_5 ( V_13 , V_44 ) == true )
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
if ( F_5 ( V_13 ,
V_36 ) == true ) {
F_20 ( V_13 ,
V_36 ) ;
F_21 ( V_13 , V_24 ) ;
}
}
}
if ( V_7 -> V_55 . V_56 == true )
goto V_54;
if ( F_1 ( V_2 ) == false )
goto V_54;
memcpy ( & V_13 -> V_27 , V_2 , sizeof( struct V_1 ) ) ;
V_13 -> V_49 = false ;
F_2 ( V_7 ) ;
goto V_50;
V_54:
V_50:
F_22 ( & V_13 -> V_41 , V_39 ) ;
}
void F_25 ( struct V_6 * V_7 ,
enum V_57 V_58 )
{
unsigned long V_39 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_51 * V_18 = & V_13 -> V_18 ;
enum V_57 * V_59 =
& ( V_18 -> V_45 . V_60 ) ;
if ( * V_59 != V_58 ) {
F_16 ( & V_13 -> V_41 , V_39 ) ;
if ( ( F_5 ( V_13 , V_44 ) == true ) ||
( * V_59 == V_61 ) )
F_17 ( V_7 ) ;
if ( F_5 ( V_13 ,
V_44 | V_36 ) == true )
F_19 ( V_7 ) ;
if ( ( F_5 ( V_13 , V_44 ) == true ) ||
( * V_59 == V_62 ) ||
( * V_59 == V_61 ) ) {
F_18 ( V_7 ) ;
}
* V_59 = V_58 ;
F_20 ( V_13 , V_47 | V_63 |
V_24 | V_36 |
V_63 ) ;
switch ( V_58 ) {
case V_61 :
F_21 ( V_13 , V_24 ) ;
break;
case V_62 :
F_21 ( V_13 , V_47 ) ;
break;
case V_64 :
F_21 ( V_13 , V_63 ) ;
break;
case V_65 :
case V_66 :
break;
}
F_22 ( & V_13 -> V_41 , V_39 ) ;
}
}
T_1 F_26 ( struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
F_16 ( & V_13 -> V_41 , V_39 ) ;
if ( F_5 ( V_13 , V_44 ) == true ) {
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
}
F_22 ( & V_13 -> V_41 , V_39 ) ;
return true ;
}
T_1 F_27 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
unsigned long V_39 ;
T_1 V_28 = true ;
if ( V_7 == NULL )
return false ;
V_13 = & V_7 -> V_14 ;
if ( V_7 -> V_53 == false )
return false ;
F_16 ( & V_13 -> V_41 , V_39 ) ;
if ( ( F_5 ( V_13 , V_42 | V_21 ) ) ||
( V_13 -> V_25 . V_26 == true ) ) {
V_28 = ( T_1 ) F_5 ( V_13 , V_42 ) ;
} else {
F_28 ( V_7 ) ;
V_28 = F_7 ( V_7 , NULL ) ;
}
F_22 ( & V_13 -> V_41 , V_39 ) ;
return V_28 ;
}
T_1 F_29 ( struct V_6 * V_7 ,
enum V_67 V_68 )
{
struct V_69 * V_70 = & V_7 -> V_55 ;
T_1 V_28 ;
V_70 -> V_71 = V_68 ;
if ( V_70 -> V_71 > 3 )
V_70 -> V_72 = 2 ;
if ( F_30 ( V_7 , V_70 ) == V_29 )
V_28 = true ;
else
V_28 = false ;
return V_28 ;
}
T_1 F_31 ( struct V_6 * V_7 ,
struct V_73 * V_74 )
{
T_1 V_75 ;
T_1 V_76 ;
T_2 V_77 ;
struct V_69 * V_70 = & V_7 -> V_55 ;
V_75 = ( V_74 -> V_78 & 0x40000000 ) > 0 ? false : true ;
V_76 = ( V_74 -> V_78 & 0x80000000 ) > 0 ? true : false ;
V_77 = V_74 -> V_78 & 0x3fffffff ;
if ( V_77 >= V_79 )
return false ;
switch ( V_74 -> V_80 ) {
case 5 :
V_70 -> V_81 = V_82 ;
break;
case 13 :
V_70 -> V_81 = V_83 ;
break;
default:
V_70 -> V_81 = V_84 ;
break;
}
memcpy ( V_70 -> V_85 [ V_77 ] . V_86 , & V_74 -> V_87 ,
V_74 -> V_80 ) ;
V_70 -> V_88 [ V_77 ] = V_74 -> V_80 ;
V_70 -> V_89 = V_77 ;
if ( F_32 ( V_7 , V_70 , V_77 ) == V_90 )
return false ;
return V_29 ;
}
