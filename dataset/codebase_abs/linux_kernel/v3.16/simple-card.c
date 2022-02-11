static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 ;
int V_14 = 0 ;
if ( V_11 -> V_15 ) {
V_13 = F_3 ( V_4 ) * V_11 -> V_15 ;
V_14 = F_4 ( V_9 , 0 , V_13 ,
V_16 ) ;
}
return V_14 ;
}
static int F_5 ( struct V_8 * V_17 ,
struct V_18 * V_19 )
{
int V_14 ;
if ( V_19 -> V_20 ) {
V_14 = F_6 ( V_17 , V_19 -> V_20 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_1 ) ;
goto V_23;
}
}
if ( V_19 -> V_24 ) {
V_14 = F_4 ( V_17 , 0 , V_19 -> V_24 , 0 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_2 ) ;
goto V_23;
}
}
if ( V_19 -> V_25 ) {
V_14 = F_8 ( V_17 , 0 , 0 ,
V_19 -> V_25 ,
V_19 -> V_26 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_3 ) ;
goto V_23;
}
}
V_14 = 0 ;
V_23:
return V_14 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
struct V_8 * V_27 = V_6 -> V_9 ;
struct V_8 * V_28 = V_6 -> V_29 ;
struct V_30 * V_31 ;
int V_32 , V_14 ;
V_32 = V_6 - V_6 -> V_12 -> V_6 ;
V_31 = & V_11 -> V_31 [ V_32 ] ;
V_14 = F_5 ( V_27 , & V_31 -> V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_28 , & V_31 -> V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int
F_10 ( struct V_33 * V_34 ,
struct V_18 * V_17 ,
const struct V_33 * * V_35 ,
const char * * V_36 )
{
struct V_33 * V_37 ;
struct V_38 * V_38 ;
int V_14 ;
V_37 = F_11 ( V_34 , L_4 , 0 ) ;
if ( ! V_37 )
return - V_39 ;
* V_35 = V_37 ;
V_14 = F_12 ( V_34 , V_36 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_13 ( V_34 , & V_17 -> V_25 , & V_17 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( F_14 ( V_34 , L_5 ) ) {
V_38 = F_15 ( V_34 , 0 ) ;
if ( F_16 ( V_38 ) ) {
V_14 = F_17 ( V_38 ) ;
return V_14 ;
}
V_17 -> V_24 = F_18 ( V_38 ) ;
} else if ( F_14 ( V_34 , L_6 ) ) {
F_19 ( V_34 ,
L_6 ,
& V_17 -> V_24 ) ;
} else {
V_38 = F_15 ( V_37 , 0 ) ;
if ( ! F_16 ( V_38 ) )
V_17 -> V_24 = F_18 ( V_38 ) ;
}
return 0 ;
}
static int F_20 ( struct V_33 * V_37 ,
struct V_40 * V_22 ,
struct V_41 * V_42 ,
struct V_30 * V_31 ,
bool V_43 )
{
struct V_33 * V_34 = NULL ;
struct V_33 * V_44 = NULL ;
struct V_33 * V_45 = NULL ;
unsigned int V_46 ;
char * V_36 ;
char V_47 [ 128 ] ;
char * V_48 = L_7 ;
int V_14 ;
if ( V_43 )
V_48 = L_8 ;
V_46 = F_21 ( V_37 , V_48 ,
& V_44 , & V_45 ) ;
V_46 &= ~ V_49 ;
snprintf ( V_47 , sizeof( V_47 ) , L_9 , V_48 ) ;
V_34 = F_22 ( V_37 , V_47 ) ;
if ( ! V_34 ) {
V_14 = - V_50 ;
F_7 ( V_22 , L_10 , V_51 , V_47 ) ;
goto V_52;
}
V_14 = F_10 ( V_34 , & V_31 -> V_29 ,
& V_42 -> V_53 ,
& V_42 -> V_54 ) ;
if ( V_14 < 0 )
goto V_52;
V_31 -> V_29 . V_20 = V_46 ;
switch ( ( ( V_34 == V_44 ) << 4 ) | ( V_34 == V_45 ) ) {
case 0x11 :
V_31 -> V_29 . V_20 |= V_55 ;
break;
case 0x10 :
V_31 -> V_29 . V_20 |= V_56 ;
break;
case 0x01 :
V_31 -> V_29 . V_20 |= V_57 ;
break;
default:
V_31 -> V_29 . V_20 |= V_58 ;
break;
}
F_23 ( V_34 ) ;
snprintf ( V_47 , sizeof( V_47 ) , L_11 , V_48 ) ;
V_34 = F_22 ( V_37 , V_47 ) ;
if ( ! V_34 ) {
V_14 = - V_50 ;
F_7 ( V_22 , L_10 , V_51 , V_47 ) ;
goto V_52;
}
V_14 = F_10 ( V_34 , & V_31 -> V_9 ,
& V_42 -> V_59 ,
& V_42 -> V_60 ) ;
if ( V_14 < 0 )
goto V_52;
if ( strlen ( V_48 ) && ! V_44 && ! V_45 ) {
F_24 ( V_22 , L_12 ,
V_51 ) ;
V_31 -> V_29 . V_20 = V_31 -> V_9 . V_20 =
F_21 ( V_34 , NULL , NULL , NULL ) |
( V_46 & ~ V_61 ) ;
} else {
V_31 -> V_9 . V_20 = V_46 ;
switch ( ( ( V_34 == V_44 ) << 4 ) | ( V_34 == V_45 ) ) {
case 0x11 :
V_31 -> V_9 . V_20 |= V_58 ;
break;
case 0x10 :
V_31 -> V_9 . V_20 |= V_57 ;
break;
case 0x01 :
V_31 -> V_9 . V_20 |= V_56 ;
break;
default:
V_31 -> V_9 . V_20 |= V_55 ;
break;
}
}
if ( ! V_42 -> V_54 || ! V_42 -> V_60 ) {
V_14 = - V_50 ;
goto V_52;
}
V_42 -> V_62 = V_42 -> V_53 ;
V_36 = F_25 ( V_22 ,
strlen ( V_42 -> V_54 ) +
strlen ( V_42 -> V_60 ) + 2 ,
V_63 ) ;
sprintf ( V_36 , L_13 , V_42 -> V_54 ,
V_42 -> V_60 ) ;
V_42 -> V_36 = V_42 -> V_64 = V_36 ;
V_42 -> V_65 = & V_66 ;
F_24 ( V_22 , L_14 , V_42 -> V_64 ) ;
F_24 ( V_22 , L_15 ,
V_42 -> V_54 ,
V_31 -> V_29 . V_20 ,
V_31 -> V_29 . V_24 ) ;
F_24 ( V_22 , L_16 ,
V_42 -> V_60 ,
V_31 -> V_9 . V_20 ,
V_31 -> V_9 . V_24 ) ;
V_52:
if ( V_34 )
F_23 ( V_34 ) ;
if ( V_44 )
F_23 ( V_44 ) ;
if ( V_45 )
F_23 ( V_45 ) ;
return V_14 ;
}
static int F_26 ( struct V_33 * V_37 ,
struct V_10 * V_11 ,
struct V_40 * V_22 ,
int V_67 )
{
struct V_41 * V_42 = V_11 -> V_68 . V_42 ;
struct V_30 * V_31 = V_11 -> V_31 ;
int V_14 ;
F_27 ( & V_11 -> V_68 , L_17 ) ;
if ( F_14 ( V_37 , L_18 ) ) {
V_14 = F_28 ( & V_11 -> V_68 ,
L_18 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_14 ( V_37 , L_19 ) ) {
V_14 = F_29 ( & V_11 -> V_68 ,
L_19 ) ;
if ( V_14 )
return V_14 ;
}
F_19 ( V_37 , L_20 ,
& V_11 -> V_15 ) ;
F_24 ( V_22 , L_21 , V_11 -> V_68 . V_36 ?
V_11 -> V_68 . V_36 : L_7 ) ;
if ( V_67 ) {
struct V_33 * V_34 = NULL ;
int V_69 ;
for ( V_69 = 0 ; ( V_34 = F_30 ( V_37 , V_34 ) ) ; V_69 ++ ) {
F_24 ( V_22 , L_22 , V_69 ) ;
V_14 = F_20 ( V_34 , V_22 , V_42 + V_69 ,
V_31 + V_69 , false ) ;
if ( V_14 < 0 ) {
F_23 ( V_34 ) ;
return V_14 ;
}
}
} else {
V_14 = F_20 ( V_37 , V_22 , V_42 , V_31 ,
true ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_11 -> V_68 . V_36 )
V_11 -> V_68 . V_36 = V_11 -> V_68 . V_42 -> V_36 ;
return 0 ;
}
static int F_31 ( struct V_70 * V_71 )
{
struct V_72 * V_12 = F_32 ( V_71 ) ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
int V_73 ;
for ( V_73 = 0 , V_42 = V_12 -> V_42 ;
V_73 < V_12 -> V_73 ;
V_73 ++ , V_42 ++ ) {
V_34 = (struct V_33 * ) V_42 -> V_53 ;
if ( V_34 )
F_23 ( V_34 ) ;
V_34 = (struct V_33 * ) V_42 -> V_59 ;
if ( V_34 )
F_23 ( V_34 ) ;
}
return 0 ;
}
static int F_33 ( struct V_70 * V_71 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
struct V_33 * V_34 = V_71 -> V_22 . V_74 ;
struct V_40 * V_22 = & V_71 -> V_22 ;
int V_73 , V_67 , V_14 ;
if ( V_34 && F_22 ( V_34 , L_23 ) ) {
V_73 = F_34 ( V_34 ) ;
V_67 = 1 ;
} else {
V_73 = 1 ;
V_67 = 0 ;
}
V_11 = F_25 ( V_22 ,
sizeof( * V_11 ) + sizeof( * V_42 ) * V_73 ,
V_63 ) ;
if ( ! V_11 )
return - V_75 ;
V_11 -> V_68 . V_76 = V_77 ;
V_11 -> V_68 . V_22 = V_22 ;
V_42 = V_11 -> V_42 ;
V_11 -> V_68 . V_42 = V_42 ;
V_11 -> V_68 . V_73 = V_73 ;
V_11 -> V_31 = F_25 ( V_22 ,
sizeof( * V_11 -> V_31 ) * V_73 ,
V_63 ) ;
if ( ! V_11 -> V_31 )
return - V_75 ;
if ( V_34 && F_35 ( V_34 ) ) {
V_14 = F_26 ( V_34 , V_11 , V_22 , V_67 ) ;
if ( V_14 < 0 ) {
if ( V_14 != - V_78 )
F_7 ( V_22 , L_24 , V_14 ) ;
goto V_23;
}
if ( V_73 == 1 )
V_42 -> V_54 = NULL ;
} else {
struct V_79 * V_80 ;
V_80 = V_22 -> V_81 ;
if ( ! V_80 ) {
F_7 ( V_22 , L_25 ) ;
return - V_50 ;
}
if ( ! V_80 -> V_36 ||
! V_80 -> V_9 . V_36 ||
! V_80 -> V_27 ||
! V_80 -> V_82 ||
! V_80 -> V_29 . V_36 ) {
F_7 ( V_22 , L_26 ) ;
return - V_50 ;
}
V_11 -> V_68 . V_36 = ( V_80 -> V_12 ) ? V_80 -> V_12 : V_80 -> V_36 ;
V_42 -> V_36 = V_80 -> V_36 ;
V_42 -> V_64 = V_80 -> V_36 ;
V_42 -> V_83 = V_80 -> V_82 ;
V_42 -> V_84 = V_80 -> V_27 ;
V_42 -> V_54 = V_80 -> V_29 . V_36 ;
V_42 -> V_60 = V_80 -> V_9 . V_36 ;
memcpy ( & V_11 -> V_31 -> V_29 , & V_80 -> V_29 ,
sizeof( V_11 -> V_31 -> V_29 ) ) ;
memcpy ( & V_11 -> V_31 -> V_9 , & V_80 -> V_9 ,
sizeof( V_11 -> V_31 -> V_9 ) ) ;
V_11 -> V_31 -> V_29 . V_20 |= V_80 -> V_46 ;
V_11 -> V_31 -> V_9 . V_20 |= V_80 -> V_46 ;
}
V_42 -> V_85 = F_9 ;
F_36 ( & V_11 -> V_68 , V_11 ) ;
V_14 = F_37 ( & V_71 -> V_22 , & V_11 -> V_68 ) ;
V_23:
F_31 ( V_71 ) ;
return V_14 ;
}
