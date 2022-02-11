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
V_10 = & V_16 -> V_16 ;
V_9 = V_10 -> V_18 ;
V_13 -> V_19 . V_20 = - 2 ;
V_13 -> V_21 |= V_22 ;
V_13 -> V_23 = V_9 ;
V_13 -> V_24 = true ;
if ( ! F_3 ( V_13 , V_25 ) &&
F_4 ( & V_16 -> V_16 ) ) {
if ( V_13 -> V_21 & V_22 )
V_13 -> V_21 ^= V_22 ;
if ( ! V_13 -> V_26 . V_27 )
F_5 ( V_7 , & V_13 -> V_28 ) ;
return true ;
} else {
int V_29 ;
V_29 = F_6 ( V_13 ) ;
if ( V_29 == V_30 )
F_7 ( & V_13 -> V_31 , V_32 ) ;
else {
if ( F_3 ( V_13 , V_25 ) ) {
struct V_33 * V_34 =
& ( V_7 -> V_35 . V_36 ) ;
V_13 -> V_21 = V_37 ;
V_11 = V_7 -> V_35 . V_36 .
V_38 ;
memcpy ( & V_34 -> V_5 ,
& V_13 -> V_28 ,
sizeof( struct V_1 ) ) ;
F_8 ( V_7 ) ;
F_9 ( V_11 ) ;
if ( F_10 ( V_7 ) != V_30 )
return false ;
V_13 -> V_24 = false ;
} else {
if ( V_13 -> V_21 & V_22 )
V_13 -> V_21 ^=
V_22 ;
if ( ! V_13 -> V_26 . V_27 )
F_5 ( V_7 ,
& V_13 -> V_28 ) ;
}
}
}
return true ;
}
T_1 F_11 ( struct V_6 * V_7 , T_1 * V_39 )
{
unsigned long V_40 ;
T_1 V_41 = true ;
struct V_12 * V_13 = & V_7 -> V_14 ;
if ( F_12 ( V_39 ) || F_13 ( V_39 ) ) {
V_41 = false ;
return V_41 ;
}
F_14 ( & V_13 -> V_42 , V_40 ) ;
if ( F_3 ( V_13 , V_43 |
V_22 ) == true ) {
V_41 = F_3 ( V_13 , V_22 ) ;
goto V_44;
}
if ( F_3 ( V_13 ,
V_45 | V_37 ) == true ) {
if ( ! memcmp ( & V_13 -> V_19 . V_46 . V_38 , V_39 ,
V_47 ) ) {
if ( ! F_3 ( V_13 , V_48 ) )
goto V_44;
} else {
F_15 ( V_7 ) ;
if ( F_3 ( V_13 , V_45 ) == true )
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
if ( ( F_3 ( V_13 ,
V_37 ) ) ) {
F_18 ( V_13 ,
V_37 ) ;
F_19 ( V_13 , V_25 ) ;
}
}
}
memcpy ( & V_13 -> V_49 , V_39 , V_47 ) ;
V_13 -> V_50 = true ;
V_41 = F_2 ( V_7 ) ;
goto V_51;
V_44:
V_51:
F_20 ( & V_13 -> V_42 , V_40 ) ;
return V_41 ;
}
void F_21 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
unsigned long V_40 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_52 * V_53 = & V_13 -> V_19 ;
if ( ! V_7 -> V_54 )
return;
F_14 ( & V_13 -> V_42 , V_40 ) ;
if ( F_3 ( V_13 , V_43 | V_22 ) ) {
F_3 ( V_13 , V_22 ) ;
goto V_55;
}
if ( F_3 ( V_13 , V_45 | V_37 ) ) {
if ( ( V_13 -> V_28 . V_4 == V_2 -> V_4 ) &&
( ! memcmp ( & V_13 -> V_28 . V_5 , V_2 -> V_5 ,
V_2 -> V_4 ) ) ) {
if ( ! F_3 ( V_13 , V_48 ) ) {
if ( ! F_22 ( V_7 ,
V_53 ) ) {
F_15 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_45 ) == true )
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_37 ) ) {
F_18 ( V_13 ,
V_37 ) ;
F_19 ( V_13 ,
V_25 ) ;
}
} else
goto V_55;
}
} else {
F_15 ( V_7 ) ;
if ( F_3 ( V_13 , V_45 ) == true )
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_37 ) == true ) {
F_18 ( V_13 ,
V_37 ) ;
F_19 ( V_13 , V_25 ) ;
}
}
}
if ( V_7 -> V_56 . V_57 == true )
goto V_55;
if ( ! F_1 ( V_2 ) )
goto V_55;
memcpy ( & V_13 -> V_28 , V_2 , sizeof( struct V_1 ) ) ;
V_13 -> V_50 = false ;
F_2 ( V_7 ) ;
goto V_51;
V_55:
V_51:
F_20 ( & V_13 -> V_42 , V_40 ) ;
}
void F_23 ( struct V_6 * V_7 ,
enum V_58 V_59 )
{
unsigned long V_40 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_52 * V_19 = & V_13 -> V_19 ;
enum V_58 * V_60 =
& ( V_19 -> V_46 . V_61 ) ;
if ( * V_60 != V_59 ) {
F_14 ( & V_13 -> V_42 , V_40 ) ;
if ( ( F_3 ( V_13 , V_45 ) == true ) ||
( * V_60 == V_62 ) )
F_15 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_45 | V_37 ) == true )
F_17 ( V_7 ) ;
if ( ( F_3 ( V_13 , V_45 ) == true ) ||
( * V_60 == V_63 ) ||
( * V_60 == V_62 ) ) {
F_16 ( V_7 ) ;
}
* V_60 = V_59 ;
F_18 ( V_13 , V_48 | V_64 |
V_25 | V_37 |
V_64 ) ;
switch ( V_59 ) {
case V_62 :
F_19 ( V_13 , V_25 ) ;
break;
case V_63 :
F_19 ( V_13 , V_48 ) ;
break;
case V_65 :
F_19 ( V_13 , V_64 ) ;
break;
case V_66 :
case V_67 :
break;
}
F_20 ( & V_13 -> V_42 , V_40 ) ;
}
}
T_1 F_24 ( struct V_6 * V_7 )
{
unsigned long V_40 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
F_14 ( & V_13 -> V_42 , V_40 ) ;
if ( F_3 ( V_13 , V_45 ) == true ) {
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
}
F_20 ( & V_13 -> V_42 , V_40 ) ;
return true ;
}
T_1 F_25 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
unsigned long V_40 ;
T_1 V_29 = true ;
if ( ! V_7 )
return false ;
V_13 = & V_7 -> V_14 ;
if ( ! V_7 -> V_54 )
return false ;
F_14 ( & V_13 -> V_42 , V_40 ) ;
if ( ( F_3 ( V_13 , V_43 | V_22 ) ) ||
( V_13 -> V_26 . V_27 == true ) ) {
V_29 = ( T_1 ) F_3 ( V_13 , V_43 ) ;
} else {
F_26 ( V_7 ) ;
V_29 = F_5 ( V_7 , NULL ) ;
}
F_20 ( & V_13 -> V_42 , V_40 ) ;
return V_29 ;
}
T_1 F_27 ( struct V_6 * V_7 ,
enum V_68 V_69 )
{
struct V_70 * V_71 = & V_7 -> V_56 ;
T_1 V_29 ;
V_71 -> V_72 = V_69 ;
if ( V_71 -> V_72 > 3 )
V_71 -> V_73 = 2 ;
if ( F_28 ( V_7 , V_71 ) == V_30 )
V_29 = true ;
else
V_29 = false ;
return V_29 ;
}
T_1 F_29 ( struct V_6 * V_7 ,
struct V_74 * V_75 )
{
T_2 V_76 ;
struct V_70 * V_71 = & V_7 -> V_56 ;
V_76 = V_75 -> V_77 & 0x3fffffff ;
if ( V_76 >= V_78 )
return false ;
switch ( V_75 -> V_79 ) {
case 5 :
V_71 -> V_80 = V_81 ;
break;
case 13 :
V_71 -> V_80 = V_82 ;
break;
default:
V_71 -> V_80 = V_83 ;
break;
}
memcpy ( V_71 -> V_84 [ V_76 ] . V_85 , & V_75 -> V_86 ,
V_75 -> V_79 ) ;
V_71 -> V_87 [ V_76 ] = V_75 -> V_79 ;
V_71 -> V_88 = V_76 ;
if ( F_30 ( V_7 , V_71 , V_76 ) == V_89 )
return false ;
return V_30 ;
}
