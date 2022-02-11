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
F_7 ( & V_13 -> V_31 ,
V_32 + F_8 ( V_33 ) ) ;
else {
if ( F_3 ( V_13 , V_25 ) ) {
struct V_34 * V_35 =
& ( V_7 -> V_36 . V_37 ) ;
V_13 -> V_21 = V_38 ;
V_11 = V_7 -> V_36 . V_37 .
V_39 ;
memcpy ( & V_35 -> V_5 ,
& V_13 -> V_28 ,
sizeof( struct V_1 ) ) ;
F_9 ( V_7 ) ;
F_10 ( V_11 ) ;
if ( F_11 ( V_7 ) != V_30 )
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
T_1 F_12 ( struct V_6 * V_7 , T_1 * V_40 )
{
unsigned long V_41 ;
T_1 V_42 = true ;
struct V_12 * V_13 = & V_7 -> V_14 ;
if ( F_13 ( V_40 ) || F_14 ( V_40 ) ) {
V_42 = false ;
return V_42 ;
}
F_15 ( & V_13 -> V_43 , V_41 ) ;
if ( F_3 ( V_13 , V_44 |
V_22 ) ) {
V_42 = F_3 ( V_13 , V_22 ) ;
goto V_45;
}
if ( F_3 ( V_13 ,
V_46 | V_38 ) ) {
if ( ! memcmp ( & V_13 -> V_19 . V_47 . V_39 , V_40 ,
V_48 ) ) {
if ( ! F_3 ( V_13 , V_49 ) )
goto V_45;
} else {
F_16 ( V_7 ) ;
if ( F_3 ( V_13 , V_46 ) )
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
if ( ( F_3 ( V_13 ,
V_38 ) ) ) {
F_19 ( V_13 ,
V_38 ) ;
F_20 ( V_13 , V_25 ) ;
}
}
}
memcpy ( & V_13 -> V_50 , V_40 , V_48 ) ;
V_13 -> V_51 = true ;
V_42 = F_2 ( V_7 ) ;
goto V_52;
V_45:
V_52:
F_21 ( & V_13 -> V_43 , V_41 ) ;
return V_42 ;
}
void F_22 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
unsigned long V_41 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_53 * V_54 = & V_13 -> V_19 ;
if ( ! V_7 -> V_55 )
return;
F_15 ( & V_13 -> V_43 , V_41 ) ;
if ( F_3 ( V_13 , V_44 | V_22 ) ) {
F_3 ( V_13 , V_22 ) ;
goto V_56;
}
if ( F_3 ( V_13 , V_46 | V_38 ) ) {
if ( ( V_13 -> V_28 . V_4 == V_2 -> V_4 ) &&
( ! memcmp ( & V_13 -> V_28 . V_5 , V_2 -> V_5 ,
V_2 -> V_4 ) ) ) {
if ( ! F_3 ( V_13 , V_49 ) ) {
if ( ! F_23 ( V_7 ,
V_54 ) ) {
F_16 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_46 ) )
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_38 ) ) {
F_19 ( V_13 ,
V_38 ) ;
F_20 ( V_13 ,
V_25 ) ;
}
} else {
goto V_56;
}
}
} else {
F_16 ( V_7 ) ;
if ( F_3 ( V_13 , V_46 ) )
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_38 ) ) {
F_19 ( V_13 ,
V_38 ) ;
F_20 ( V_13 , V_25 ) ;
}
}
}
if ( V_7 -> V_57 . V_58 )
goto V_56;
if ( ! F_1 ( V_2 ) )
goto V_56;
memcpy ( & V_13 -> V_28 , V_2 , sizeof( struct V_1 ) ) ;
V_13 -> V_51 = false ;
F_2 ( V_7 ) ;
goto V_52;
V_56:
V_52:
F_21 ( & V_13 -> V_43 , V_41 ) ;
}
void F_24 ( struct V_6 * V_7 ,
enum V_59 V_60 )
{
unsigned long V_41 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
struct V_53 * V_19 = & V_13 -> V_19 ;
enum V_59 * V_61 =
& ( V_19 -> V_47 . V_62 ) ;
if ( * V_61 != V_60 ) {
F_15 ( & V_13 -> V_43 , V_41 ) ;
if ( F_3 ( V_13 , V_46 ) ||
( * V_61 == V_63 ) )
F_16 ( V_7 ) ;
if ( F_3 ( V_13 ,
V_46 | V_38 ) )
F_18 ( V_7 ) ;
if ( F_3 ( V_13 , V_46 ) ||
( * V_61 == V_64 ) ||
( * V_61 == V_63 ) ) {
F_17 ( V_7 ) ;
}
* V_61 = V_60 ;
F_19 ( V_13 , V_49 | V_65 |
V_25 | V_38 ) ;
switch ( V_60 ) {
case V_63 :
F_20 ( V_13 , V_25 ) ;
break;
case V_64 :
F_20 ( V_13 , V_49 ) ;
break;
case V_66 :
F_20 ( V_13 , V_65 ) ;
break;
case V_67 :
case V_68 :
break;
}
F_21 ( & V_13 -> V_43 , V_41 ) ;
}
}
T_1 F_25 ( struct V_6 * V_7 )
{
unsigned long V_41 ;
struct V_12 * V_13 = & V_7 -> V_14 ;
F_15 ( & V_13 -> V_43 , V_41 ) ;
if ( F_3 ( V_13 , V_46 ) ) {
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
}
F_21 ( & V_13 -> V_43 , V_41 ) ;
return true ;
}
T_1 F_26 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = NULL ;
unsigned long V_41 ;
T_1 V_29 = true ;
if ( ! V_7 )
return false ;
V_13 = & V_7 -> V_14 ;
if ( ! V_7 -> V_55 )
return false ;
F_15 ( & V_13 -> V_43 , V_41 ) ;
if ( F_3 ( V_13 , V_44 | V_22 ) ||
V_13 -> V_26 . V_27 ) {
V_29 = ( T_1 ) F_3 ( V_13 , V_44 ) ;
} else {
F_27 ( V_7 ) ;
V_29 = F_5 ( V_7 , NULL ) ;
}
F_21 ( & V_13 -> V_43 , V_41 ) ;
return V_29 ;
}
T_1 F_28 ( struct V_6 * V_7 ,
enum V_69 V_70 )
{
struct V_71 * V_72 = & V_7 -> V_57 ;
T_1 V_29 ;
V_72 -> V_73 = V_70 ;
if ( V_72 -> V_73 > 3 )
V_72 -> V_74 = 2 ;
if ( F_29 ( V_7 , V_72 ) == V_30 )
V_29 = true ;
else
V_29 = false ;
return V_29 ;
}
T_1 F_30 ( struct V_6 * V_7 ,
struct V_75 * V_76 )
{
T_2 V_77 ;
struct V_71 * V_72 = & V_7 -> V_57 ;
V_77 = V_76 -> V_78 & 0x3fffffff ;
if ( V_77 >= V_79 )
return false ;
switch ( V_76 -> V_80 ) {
case 5 :
V_72 -> V_81 = V_82 ;
break;
case 13 :
V_72 -> V_81 = V_83 ;
break;
default:
V_72 -> V_81 = V_84 ;
break;
}
memcpy ( V_72 -> V_85 [ V_77 ] . V_86 , & V_76 -> V_87 ,
V_76 -> V_80 ) ;
V_72 -> V_88 [ V_77 ] = V_76 -> V_80 ;
V_72 -> V_89 = V_77 ;
if ( F_31 ( V_7 , V_72 , V_77 ) == V_90 )
return false ;
return V_30 ;
}
