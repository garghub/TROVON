static void F_1 ( union V_1 * V_2 )
{
void * V_3 = NULL ;
union V_1 * V_4 ;
union V_1 * V_5 ;
union V_1 * V_6 ;
union V_1 * V_7 ;
union V_1 * * V_8 ;
F_2 ( V_9 , V_2 ) ;
if ( ! V_2 ) {
V_10 ;
}
switch ( V_2 -> V_11 . type ) {
case V_12 :
F_3 ( ( V_13 ,
L_1 , V_2 ,
V_2 -> string . V_14 ) ) ;
if ( ! ( V_2 -> V_11 . V_15 & V_16 ) ) {
V_3 = V_2 -> string . V_14 ;
}
break;
case V_17 :
F_3 ( ( V_13 ,
L_2 , V_2 ,
V_2 -> V_18 . V_14 ) ) ;
if ( ! ( V_2 -> V_11 . V_15 & V_16 ) ) {
V_3 = V_2 -> V_18 . V_14 ;
}
break;
case V_19 :
F_3 ( ( V_13 ,
L_3 ,
V_2 -> V_20 . V_21 ) ) ;
V_3 = V_2 -> V_20 . V_22 ;
break;
case V_23 :
if ( V_2 -> V_24 . V_25 ) {
( void ) F_4 ( V_2 -> V_24 .
V_25 ) ;
}
case V_26 :
case V_27 :
V_4 = V_2 -> V_28 . V_29 ;
while ( V_4 ) {
V_6 = V_4 -> V_30 . V_31 ;
F_5 ( V_4 ) ;
V_4 = V_6 ;
}
break;
case V_32 :
F_3 ( ( V_13 ,
L_4 ,
V_2 , V_2 -> V_33 . V_34 ) ) ;
if ( V_2 == V_35 ) {
( void )
F_6
( V_36 ) ;
V_36 = NULL ;
F_7 ( V_2 -> V_33 . V_34 ) ;
V_35 = NULL ;
} else {
F_8 ( V_2 ) ;
F_7 ( V_2 -> V_33 . V_34 ) ;
}
break;
case V_37 :
F_3 ( ( V_13 ,
L_5 ,
V_2 , V_2 -> V_38 . V_39 ) ) ;
( void ) F_6 ( V_2 -> V_38 . V_39 ) ;
V_2 -> V_38 . V_39 = NULL ;
break;
case V_40 :
F_3 ( ( V_13 ,
L_6 , V_2 ) ) ;
if ( V_2 -> V_41 . V_33 ) {
F_7 ( V_2 -> V_41 . V_33 -> V_33 .
V_34 ) ;
F_9 ( V_2 -> V_41 . V_33 ) ;
V_2 -> V_41 . V_33 = NULL ;
}
break;
case V_42 :
F_3 ( ( V_13 ,
L_7 , V_2 ) ) ;
if ( ! ( V_2 -> V_43 . V_44 -> V_15 & V_45 ) ) {
F_10 ( V_2 -> V_43 . V_46 ,
V_2 -> V_43 . V_44 ) ;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
V_4 = V_2 -> V_43 . V_29 ;
if ( V_4 ) {
V_6 =
V_4 -> V_30 . V_47 ;
V_7 = V_6 ;
V_8 =
& V_4 -> V_30 . V_47 ;
while ( V_6 ) {
if ( V_6 == V_2 ) {
* V_8 =
V_6 -> V_43 . V_31 ;
break;
}
V_8 = & V_6 -> V_43 . V_31 ;
V_6 = V_6 -> V_43 . V_31 ;
if ( V_6 == V_7 ) {
F_12 ( ( V_48 ,
L_8 ,
V_4 ) ) ;
V_10 ;
}
}
if ( V_4 -> V_30 . V_49 &
V_50 ) {
if ( V_4 -> V_30 . V_51 ) {
( void ) V_4 ->
V_30 . V_51 ( V_2 ,
V_52 ,
V_4 ->
V_30 .
V_53 ,
& V_5 ->
V_54 .
V_55 ) ;
}
}
F_5 ( V_4 ) ;
}
F_9 ( V_5 ) ;
}
break;
case V_56 :
F_3 ( ( V_13 ,
L_9 , V_2 ) ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_5 ) ;
}
break;
case V_57 :
F_3 ( ( V_13 ,
L_10 , V_2 ) ) ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_5 ) ;
}
break;
default:
break;
}
if ( V_3 ) {
F_3 ( ( V_13 ,
L_11 , V_3 ) ) ;
F_13 ( V_3 ) ;
}
F_3 ( ( V_13 , L_12 ,
V_2 , F_14 ( V_2 ) ) ) ;
F_9 ( V_2 ) ;
V_10 ;
}
void F_15 ( union V_1 * * V_58 )
{
union V_1 * * V_59 ;
F_16 () ;
for ( V_59 = V_58 ; * V_59 ; V_59 ++ ) {
F_5 ( * V_59 ) ;
}
F_13 ( V_58 ) ;
return;
}
static void
F_17 ( union V_1 * V_2 , T_1 V_60 )
{
T_2 V_61 ;
T_2 V_62 = 0 ;
T_3 V_63 ;
F_18 ( V_64 ) ;
if ( ! V_2 ) {
return;
}
V_63 = F_19 ( V_65 ) ;
V_61 = V_2 -> V_11 . V_66 ;
switch ( V_60 ) {
case V_67 :
V_62 = V_61 + 1 ;
V_2 -> V_11 . V_66 = V_62 ;
F_20 ( V_65 , V_63 ) ;
if ( ! V_61 ) {
F_21 ( ( V_48 ,
L_13 ,
V_2 ) ) ;
}
F_3 ( ( V_13 ,
L_14 ,
V_2 , V_2 -> V_11 . type , V_62 ) ) ;
break;
case V_68 :
if ( V_61 ) {
V_62 = V_61 - 1 ;
V_2 -> V_11 . V_66 = V_62 ;
}
F_20 ( V_65 , V_63 ) ;
if ( ! V_61 ) {
F_21 ( ( V_48 ,
L_15 ,
V_2 ) ) ;
}
F_3 ( ( V_13 ,
L_16 ,
V_2 , V_2 -> V_11 . type , V_62 ) ) ;
if ( V_62 == 0 ) {
F_1 ( V_2 ) ;
}
break;
default:
F_20 ( V_65 , V_63 ) ;
F_12 ( ( V_48 , L_17 ,
V_60 ) ) ;
return;
}
if ( V_62 > V_69 ) {
F_21 ( ( V_48 ,
L_18 ,
V_62 , V_2 , V_2 -> V_11 . type ) ) ;
}
}
T_4
F_22 ( union V_1 * V_2 , T_2 V_60 )
{
T_4 V_70 = V_71 ;
union V_72 * V_73 = NULL ;
union V_1 * V_74 = NULL ;
union V_1 * V_75 ;
union V_72 * V_76 ;
T_1 V_77 ;
F_18 ( V_78 ) ;
while ( V_2 ) {
if ( F_23 ( V_2 ) == V_79 ) {
F_3 ( ( V_13 ,
L_19 , V_2 ) ) ;
return ( V_71 ) ;
}
switch ( V_2 -> V_11 . type ) {
case V_23 :
case V_26 :
case V_80 :
case V_27 :
for ( V_77 = 0 ; V_77 < V_81 ; V_77 ++ ) {
V_75 =
V_2 -> V_28 . V_82 [ V_77 ] ;
while ( V_75 ) {
V_74 =
V_75 -> V_83 . V_31 [ V_77 ] ;
F_17 ( V_75 ,
V_60 ) ;
V_75 = V_74 ;
}
}
break;
case V_19 :
for ( V_77 = 0 ; V_77 < V_2 -> V_20 . V_21 ; V_77 ++ ) {
V_74 = V_2 -> V_20 . V_22 [ V_77 ] ;
if ( ! V_74 ) {
continue;
}
switch ( V_74 -> V_11 . type ) {
case V_84 :
case V_12 :
case V_17 :
F_17 ( V_74 ,
V_60 ) ;
break;
default:
V_70 =
F_24
( V_74 , V_60 , & V_73 ) ;
if ( F_25 ( V_70 ) ) {
goto V_85;
}
break;
}
}
V_74 = NULL ;
break;
case V_56 :
V_74 = V_2 -> V_86 . V_87 ;
break;
case V_88 :
V_74 = V_2 -> V_89 . V_90 ;
break;
case V_57 :
V_74 = V_2 -> V_91 . V_92 ;
V_70 =
F_24 ( V_2 ->
V_91 .
V_90 ,
V_60 ,
& V_73 ) ;
if ( F_25 ( V_70 ) ) {
goto V_85;
}
break;
case V_93 :
V_74 = V_2 -> V_94 . V_95 ;
V_70 =
F_24 ( V_2 ->
V_94 .
V_96 ,
V_60 ,
& V_73 ) ;
if ( F_25 ( V_70 ) ) {
goto V_85;
}
break;
case V_97 :
if ( ( V_2 -> V_98 . V_99 == V_100 ) ||
( V_2 -> V_98 . V_99 == V_101 ) ) {
V_74 = V_2 -> V_98 . V_2 ;
}
break;
case V_42 :
default:
break;
}
F_17 ( V_2 , V_60 ) ;
V_2 = NULL ;
if ( V_74 ) {
V_2 = V_74 ;
V_74 = NULL ;
} else if ( V_73 ) {
V_76 = F_26 ( & V_73 ) ;
V_2 = V_76 -> V_102 . V_2 ;
F_27 ( V_76 ) ;
}
}
return ( V_71 ) ;
V_85:
F_28 ( ( V_48 , V_70 ,
L_20 ) ) ;
while ( V_73 ) {
V_76 = F_26 ( & V_73 ) ;
F_27 ( V_76 ) ;
}
return ( V_70 ) ;
}
void F_29 ( union V_1 * V_2 )
{
F_18 ( V_103 ) ;
if ( ! F_30 ( V_2 ) ) {
return;
}
F_3 ( ( V_13 ,
L_21 ,
V_2 , V_2 -> V_11 . V_66 ) ) ;
( void ) F_22 ( V_2 , V_67 ) ;
return;
}
void F_5 ( union V_1 * V_2 )
{
F_18 ( V_104 ) ;
if ( ! V_2 ||
( F_23 ( V_2 ) == V_79 ) ) {
return;
}
if ( ! F_30 ( V_2 ) ) {
return;
}
F_3 ( ( V_13 ,
L_22 ,
V_2 , V_2 -> V_11 . V_66 ) ) ;
( void ) F_22 ( V_2 , V_68 ) ;
return;
}
