static void F_1 ( union V_1 * V_2 )
{
void * V_3 = NULL ;
union V_1 * V_4 ;
union V_1 * V_5 ;
union V_1 * V_6 ;
union V_1 * * V_7 ;
F_2 ( V_8 , V_2 ) ;
if ( ! V_2 ) {
V_9 ;
}
switch ( V_2 -> V_10 . type ) {
case V_11 :
F_3 ( ( V_12 ,
L_1 , V_2 ,
V_2 -> string . V_13 ) ) ;
if ( ! ( V_2 -> V_10 . V_14 & V_15 ) ) {
V_3 = V_2 -> string . V_13 ;
}
break;
case V_16 :
F_3 ( ( V_12 ,
L_2 , V_2 ,
V_2 -> V_17 . V_13 ) ) ;
if ( ! ( V_2 -> V_10 . V_14 & V_15 ) ) {
V_3 = V_2 -> V_17 . V_13 ;
}
break;
case V_18 :
F_3 ( ( V_12 ,
L_3 ,
V_2 -> V_19 . V_20 ) ) ;
V_3 = V_2 -> V_19 . V_21 ;
break;
case V_22 :
if ( V_2 -> V_23 . V_24 ) {
( void ) F_4 ( V_2 -> V_23 .
V_24 ) ;
}
case V_25 :
case V_26 :
V_4 = V_2 -> V_27 . V_28 ;
while ( V_4 ) {
V_6 = V_4 -> V_29 . V_30 ;
F_5 ( V_4 ) ;
V_4 = V_6 ;
}
break;
case V_31 :
F_3 ( ( V_12 ,
L_4 ,
V_2 , V_2 -> V_32 . V_33 ) ) ;
if ( V_2 == V_34 ) {
( void )
F_6
( V_35 ) ;
V_35 = NULL ;
F_7 ( V_2 -> V_32 . V_33 ) ;
V_34 = NULL ;
} else {
F_8 ( V_2 ) ;
F_7 ( V_2 -> V_32 . V_33 ) ;
}
break;
case V_36 :
F_3 ( ( V_12 ,
L_5 ,
V_2 , V_2 -> V_37 . V_38 ) ) ;
( void ) F_6 ( V_2 -> V_37 . V_38 ) ;
V_2 -> V_37 . V_38 = NULL ;
break;
case V_39 :
F_3 ( ( V_12 ,
L_6 , V_2 ) ) ;
if ( V_2 -> V_40 . V_32 ) {
F_7 ( V_2 -> V_40 . V_32 -> V_32 .
V_33 ) ;
F_9 ( V_2 -> V_40 . V_32 ) ;
V_2 -> V_40 . V_32 = NULL ;
}
break;
case V_41 :
F_3 ( ( V_12 ,
L_7 , V_2 ) ) ;
if ( ! ( V_2 -> V_42 . V_43 -> V_14 & V_44 ) ) {
F_10 ( V_2 -> V_42 . V_45 ,
V_2 -> V_42 . V_43 ) ;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
V_4 = V_2 -> V_42 . V_28 ;
if ( V_4 ) {
V_6 =
V_4 -> V_29 . V_46 ;
V_7 =
& V_4 -> V_29 . V_46 ;
while ( V_6 ) {
if ( V_6 == V_2 ) {
* V_7 =
V_6 -> V_42 . V_30 ;
break;
}
V_7 = & V_6 -> V_42 . V_30 ;
V_6 = V_6 -> V_42 . V_30 ;
}
if ( V_4 -> V_29 . V_47 &
V_48 ) {
if ( V_4 -> V_29 . V_49 ) {
( void ) V_4 ->
V_29 . V_49 ( V_2 ,
V_50 ,
V_4 ->
V_29 .
V_51 ,
& V_5 ->
V_52 .
V_53 ) ;
}
}
F_5 ( V_4 ) ;
}
F_9 ( V_5 ) ;
}
break;
case V_54 :
F_3 ( ( V_12 ,
L_8 , V_2 ) ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_5 ) ;
}
break;
case V_55 :
F_3 ( ( V_12 ,
L_9 , V_2 ) ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_5 ) ;
}
break;
default:
break;
}
if ( V_3 ) {
F_3 ( ( V_12 ,
L_10 , V_3 ) ) ;
F_12 ( V_3 ) ;
}
F_3 ( ( V_12 , L_11 ,
V_2 , F_13 ( V_2 ) ) ) ;
F_9 ( V_2 ) ;
V_9 ;
}
void F_14 ( union V_1 * * V_56 )
{
union V_1 * * V_57 ;
F_15 () ;
for ( V_57 = V_56 ; * V_57 ; V_57 ++ ) {
F_5 ( * V_57 ) ;
}
F_12 ( V_56 ) ;
return;
}
static void
F_16 ( union V_1 * V_2 , T_1 V_58 )
{
T_2 V_20 ;
T_2 V_59 ;
F_17 ( V_60 ) ;
if ( ! V_2 ) {
return;
}
V_20 = V_2 -> V_10 . V_61 ;
V_59 = V_20 ;
switch ( V_58 ) {
case V_62 :
V_59 ++ ;
V_2 -> V_10 . V_61 = V_59 ;
F_3 ( ( V_12 ,
L_12 ,
V_2 , V_59 ) ) ;
break;
case V_63 :
if ( V_20 < 1 ) {
F_3 ( ( V_12 ,
L_13 ,
V_2 , V_59 ) ) ;
V_59 = 0 ;
} else {
V_59 -- ;
F_3 ( ( V_12 ,
L_14 ,
V_2 , V_59 ) ) ;
}
if ( V_2 -> V_10 . type == V_39 ) {
F_3 ( ( V_12 ,
L_15 ,
V_2 , V_59 ) ) ;
}
V_2 -> V_10 . V_61 = V_59 ;
if ( V_59 == 0 ) {
F_1 ( V_2 ) ;
}
break;
case V_64 :
F_3 ( ( V_12 ,
L_16 ,
V_2 , V_20 ) ) ;
V_59 = 0 ;
V_2 -> V_10 . V_61 = V_59 ;
F_1 ( V_2 ) ;
break;
default:
F_18 ( ( V_65 , L_17 , V_58 ) ) ;
break;
}
if ( V_20 > V_66 ) {
F_19 ( ( V_65 ,
L_18 ,
V_20 , V_2 ) ) ;
}
}
T_3
F_20 ( union V_1 * V_2 , T_2 V_58 )
{
T_3 V_67 = V_68 ;
union V_69 * V_70 = NULL ;
union V_1 * V_71 = NULL ;
union V_1 * V_72 ;
union V_69 * V_73 ;
T_1 V_74 ;
F_17 ( V_75 ) ;
while ( V_2 ) {
if ( F_21 ( V_2 ) == V_76 ) {
F_3 ( ( V_12 ,
L_19 , V_2 ) ) ;
return ( V_68 ) ;
}
switch ( V_2 -> V_10 . type ) {
case V_22 :
case V_25 :
case V_77 :
case V_26 :
for ( V_74 = 0 ; V_74 < V_78 ; V_74 ++ ) {
V_72 =
V_2 -> V_27 . V_79 [ V_74 ] ;
while ( V_72 ) {
V_71 =
V_72 -> V_80 . V_30 [ V_74 ] ;
F_16 ( V_72 ,
V_58 ) ;
V_72 = V_71 ;
}
}
break;
case V_18 :
for ( V_74 = 0 ; V_74 < V_2 -> V_19 . V_20 ; V_74 ++ ) {
V_71 = V_2 -> V_19 . V_21 [ V_74 ] ;
if ( ! V_71 ) {
continue;
}
switch ( V_71 -> V_10 . type ) {
case V_81 :
case V_11 :
case V_16 :
F_16 ( V_71 ,
V_58 ) ;
break;
default:
V_67 =
F_22
( V_71 , V_58 , & V_70 ) ;
if ( F_23 ( V_67 ) ) {
goto V_82;
}
break;
}
}
V_71 = NULL ;
break;
case V_54 :
V_71 = V_2 -> V_83 . V_84 ;
break;
case V_85 :
V_71 = V_2 -> V_86 . V_87 ;
break;
case V_55 :
V_71 = V_2 -> V_88 . V_89 ;
V_67 =
F_22 ( V_2 ->
V_88 .
V_87 ,
V_58 ,
& V_70 ) ;
if ( F_23 ( V_67 ) ) {
goto V_82;
}
break;
case V_90 :
V_71 = V_2 -> V_91 . V_92 ;
V_67 =
F_22 ( V_2 ->
V_91 .
V_93 ,
V_58 ,
& V_70 ) ;
if ( F_23 ( V_67 ) ) {
goto V_82;
}
break;
case V_94 :
if ( ( V_2 -> V_95 . V_96 == V_97 ) ||
( V_2 -> V_95 . V_96 == V_98 ) ) {
V_71 = V_2 -> V_95 . V_2 ;
}
break;
case V_41 :
default:
break;
}
F_16 ( V_2 , V_58 ) ;
V_2 = NULL ;
if ( V_71 ) {
V_2 = V_71 ;
V_71 = NULL ;
} else if ( V_70 ) {
V_73 = F_24 ( & V_70 ) ;
V_2 = V_73 -> V_99 . V_2 ;
F_25 ( V_73 ) ;
}
}
return ( V_68 ) ;
V_82:
F_26 ( ( V_65 , V_67 ,
L_20 ) ) ;
while ( V_70 ) {
V_73 = F_24 ( & V_70 ) ;
F_25 ( V_73 ) ;
}
return ( V_67 ) ;
}
void F_27 ( union V_1 * V_2 )
{
F_17 ( V_100 ) ;
if ( ! F_28 ( V_2 ) ) {
return;
}
F_3 ( ( V_12 ,
L_21 ,
V_2 , V_2 -> V_10 . V_61 ) ) ;
( void ) F_20 ( V_2 , V_62 ) ;
return;
}
void F_5 ( union V_1 * V_2 )
{
F_17 ( V_101 ) ;
if ( ! V_2 ||
( F_21 ( V_2 ) == V_76 ) ) {
return;
}
if ( ! F_28 ( V_2 ) ) {
return;
}
F_3 ( ( V_12 ,
L_22 ,
V_2 , V_2 -> V_10 . V_61 ) ) ;
( void ) F_20 ( V_2 , V_63 ) ;
return;
}
