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
T_2 V_59 ;
T_2 V_60 = 0 ;
T_3 V_61 ;
F_17 ( V_62 ) ;
if ( ! V_2 ) {
return;
}
V_61 = F_18 ( V_63 ) ;
V_59 = V_2 -> V_10 . V_64 ;
switch ( V_58 ) {
case V_65 :
V_60 = V_59 + 1 ;
V_2 -> V_10 . V_64 = V_60 ;
F_19 ( V_63 , V_61 ) ;
if ( ! V_59 ) {
F_20 ( ( V_66 ,
L_12 ,
V_2 ) ) ;
}
F_3 ( ( V_12 ,
L_13 ,
V_2 , V_2 -> V_10 . type , V_60 ) ) ;
break;
case V_67 :
if ( V_59 ) {
V_60 = V_59 - 1 ;
V_2 -> V_10 . V_64 = V_60 ;
}
F_19 ( V_63 , V_61 ) ;
if ( ! V_59 ) {
F_20 ( ( V_66 ,
L_14 ,
V_2 ) ) ;
}
F_3 ( ( V_12 ,
L_15 ,
V_2 , V_2 -> V_10 . type , V_60 ) ) ;
if ( V_60 == 0 ) {
F_1 ( V_2 ) ;
}
break;
default:
F_19 ( V_63 , V_61 ) ;
F_21 ( ( V_66 , L_16 ,
V_58 ) ) ;
return;
}
if ( V_60 > V_68 ) {
F_20 ( ( V_66 ,
L_17 ,
V_60 , V_2 , V_2 -> V_10 . type ) ) ;
}
}
T_4
F_22 ( union V_1 * V_2 , T_2 V_58 )
{
T_4 V_69 = V_70 ;
union V_71 * V_72 = NULL ;
union V_1 * V_73 = NULL ;
union V_1 * V_74 ;
union V_71 * V_75 ;
T_1 V_76 ;
F_17 ( V_77 ) ;
while ( V_2 ) {
if ( F_23 ( V_2 ) == V_78 ) {
F_3 ( ( V_12 ,
L_18 , V_2 ) ) ;
return ( V_70 ) ;
}
switch ( V_2 -> V_10 . type ) {
case V_22 :
case V_25 :
case V_79 :
case V_26 :
for ( V_76 = 0 ; V_76 < V_80 ; V_76 ++ ) {
V_74 =
V_2 -> V_27 . V_81 [ V_76 ] ;
while ( V_74 ) {
V_73 =
V_74 -> V_82 . V_30 [ V_76 ] ;
F_16 ( V_74 ,
V_58 ) ;
V_74 = V_73 ;
}
}
break;
case V_18 :
for ( V_76 = 0 ; V_76 < V_2 -> V_19 . V_20 ; V_76 ++ ) {
V_73 = V_2 -> V_19 . V_21 [ V_76 ] ;
if ( ! V_73 ) {
continue;
}
switch ( V_73 -> V_10 . type ) {
case V_83 :
case V_11 :
case V_16 :
F_16 ( V_73 ,
V_58 ) ;
break;
default:
V_69 =
F_24
( V_73 , V_58 , & V_72 ) ;
if ( F_25 ( V_69 ) ) {
goto V_84;
}
break;
}
}
V_73 = NULL ;
break;
case V_54 :
V_73 = V_2 -> V_85 . V_86 ;
break;
case V_87 :
V_73 = V_2 -> V_88 . V_89 ;
break;
case V_55 :
V_73 = V_2 -> V_90 . V_91 ;
V_69 =
F_24 ( V_2 ->
V_90 .
V_89 ,
V_58 ,
& V_72 ) ;
if ( F_25 ( V_69 ) ) {
goto V_84;
}
break;
case V_92 :
V_73 = V_2 -> V_93 . V_94 ;
V_69 =
F_24 ( V_2 ->
V_93 .
V_95 ,
V_58 ,
& V_72 ) ;
if ( F_25 ( V_69 ) ) {
goto V_84;
}
break;
case V_96 :
if ( ( V_2 -> V_97 . V_98 == V_99 ) ||
( V_2 -> V_97 . V_98 == V_100 ) ) {
V_73 = V_2 -> V_97 . V_2 ;
}
break;
case V_41 :
default:
break;
}
F_16 ( V_2 , V_58 ) ;
V_2 = NULL ;
if ( V_73 ) {
V_2 = V_73 ;
V_73 = NULL ;
} else if ( V_72 ) {
V_75 = F_26 ( & V_72 ) ;
V_2 = V_75 -> V_101 . V_2 ;
F_27 ( V_75 ) ;
}
}
return ( V_70 ) ;
V_84:
F_28 ( ( V_66 , V_69 ,
L_19 ) ) ;
while ( V_72 ) {
V_75 = F_26 ( & V_72 ) ;
F_27 ( V_75 ) ;
}
return ( V_69 ) ;
}
void F_29 ( union V_1 * V_2 )
{
F_17 ( V_102 ) ;
if ( ! F_30 ( V_2 ) ) {
return;
}
F_3 ( ( V_12 ,
L_20 ,
V_2 , V_2 -> V_10 . V_64 ) ) ;
( void ) F_22 ( V_2 , V_65 ) ;
return;
}
void F_5 ( union V_1 * V_2 )
{
F_17 ( V_103 ) ;
if ( ! V_2 ||
( F_23 ( V_2 ) == V_78 ) ) {
return;
}
if ( ! F_30 ( V_2 ) ) {
return;
}
F_3 ( ( V_12 ,
L_21 ,
V_2 , V_2 -> V_10 . V_64 ) ) ;
( void ) F_22 ( V_2 , V_67 ) ;
return;
}
