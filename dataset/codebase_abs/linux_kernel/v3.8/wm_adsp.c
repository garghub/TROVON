static struct V_1 const * F_1 ( struct V_2 * V_3 ,
int type )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ )
if ( V_3 -> V_6 [ V_4 ] . type == type )
return & V_3 -> V_6 [ V_4 ] ;
return NULL ;
}
static int F_2 ( struct V_2 * V_3 )
{
const struct V_7 * V_7 ;
struct V_8 * V_8 = V_3 -> V_8 ;
unsigned int V_9 = 0 ;
const struct V_10 * V_11 ;
const struct V_12 * V_13 ;
const struct V_14 * V_15 ;
const struct V_16 * V_17 ;
const struct V_18 * V_19 ;
const struct V_1 * V_6 ;
const char * V_20 ;
char * V_21 , * V_22 ;
void * V_23 ;
unsigned int V_24 ;
int V_25 = 0 ;
int V_26 , V_27 , type , V_28 ;
V_21 = F_3 ( V_29 , V_30 ) ;
if ( V_21 == NULL )
return - V_31 ;
snprintf ( V_21 , V_29 , L_1 , V_3 -> V_32 , V_3 -> V_33 ) ;
V_21 [ V_29 - 1 ] = '\0' ;
V_26 = F_4 ( & V_7 , V_21 , V_3 -> V_34 ) ;
if ( V_26 != 0 ) {
F_5 ( V_3 , L_2 , V_21 ) ;
goto V_35;
}
V_26 = - V_36 ;
V_9 = sizeof( * V_11 ) + sizeof( * V_13 ) + sizeof( * V_17 ) ;
if ( V_9 >= V_7 -> V_37 ) {
F_5 ( V_3 , L_3 ,
V_21 , V_7 -> V_37 ) ;
goto V_38;
}
V_11 = ( void * ) & V_7 -> V_39 [ 0 ] ;
if ( memcmp ( & V_11 -> V_40 [ 0 ] , L_4 , 4 ) != 0 ) {
F_5 ( V_3 , L_5 , V_21 ) ;
goto V_38;
}
if ( V_11 -> V_41 != 0 ) {
F_5 ( V_3 , L_6 ,
V_21 , V_11 -> V_41 ) ;
goto V_38;
}
if ( V_11 -> V_42 != V_3 -> type ) {
F_5 ( V_3 , L_7 ,
V_21 , V_11 -> V_42 , V_3 -> type ) ;
goto V_38;
}
switch ( V_3 -> type ) {
case V_43 :
V_9 = sizeof( * V_11 ) + sizeof( * V_13 ) + sizeof( * V_17 ) ;
V_13 = ( void * ) & ( V_11 [ 1 ] ) ;
V_17 = ( void * ) & ( V_13 [ 1 ] ) ;
V_28 = sizeof( * V_13 ) ;
F_6 ( V_3 , L_8 ,
V_21 , F_7 ( V_13 -> V_44 ) ,
F_7 ( V_13 -> V_45 ) ,
F_7 ( V_13 -> V_46 ) ) ;
break;
case V_47 :
V_9 = sizeof( * V_11 ) + sizeof( * V_15 ) + sizeof( * V_17 ) ;
V_15 = ( void * ) & ( V_11 [ 1 ] ) ;
V_17 = ( void * ) & ( V_15 [ 1 ] ) ;
V_28 = sizeof( * V_15 ) ;
F_6 ( V_3 , L_9 ,
V_21 , F_7 ( V_15 -> V_48 ) ,
F_7 ( V_15 -> V_49 ) ,
F_7 ( V_15 -> V_45 ) ,
F_7 ( V_15 -> V_46 ) ) ;
break;
default:
F_8 ( NULL == L_10 ) ;
goto V_38;
}
if ( F_7 ( V_11 -> V_50 ) != sizeof( * V_11 ) +
V_28 + sizeof( * V_17 ) ) {
F_5 ( V_3 , L_11 ,
V_21 , F_7 ( V_11 -> V_50 ) ) ;
goto V_38;
}
F_6 ( V_3 , L_12 , V_21 ,
F_9 ( V_17 -> V_51 ) ) ;
while ( V_9 < V_7 -> V_37 &&
V_9 - V_7 -> V_37 > sizeof( * V_19 ) ) {
V_19 = ( void * ) & ( V_7 -> V_39 [ V_9 ] ) ;
V_20 = L_13 ;
V_24 = 0 ;
V_22 = NULL ;
V_27 = F_7 ( V_19 -> V_27 ) & 0xffffff ;
type = F_10 ( V_19 -> type ) & 0xff ;
V_6 = F_1 ( V_3 , type ) ;
switch ( type ) {
case V_52 :
V_20 = L_14 ;
V_22 = F_3 ( F_7 ( V_19 -> V_50 ) + 1 ,
V_30 ) ;
break;
case V_53 :
V_20 = L_15 ;
V_22 = F_3 ( F_7 ( V_19 -> V_50 ) + 1 ,
V_30 ) ;
break;
case V_54 :
V_20 = L_16 ;
V_24 = V_27 ;
break;
case V_55 :
F_8 ( ! V_6 ) ;
V_20 = L_17 ;
V_24 = V_6 -> V_56 + ( V_27 * 3 ) ;
break;
case V_57 :
F_8 ( ! V_6 ) ;
V_20 = L_18 ;
V_24 = V_6 -> V_56 + ( V_27 * 2 ) ;
break;
case V_58 :
F_8 ( ! V_6 ) ;
V_20 = L_19 ;
V_24 = V_6 -> V_56 + ( V_27 * 2 ) ;
break;
case V_59 :
F_8 ( ! V_6 ) ;
V_20 = L_20 ;
V_24 = V_6 -> V_56 + ( V_27 * 2 ) ;
break;
case V_60 :
F_8 ( ! V_6 ) ;
V_20 = L_21 ;
V_24 = V_6 -> V_56 + ( V_27 * 2 ) ;
break;
default:
F_11 ( V_3 ,
L_22 ,
V_21 , V_25 , type , V_9 , V_9 ) ;
break;
}
F_6 ( V_3 , L_23 , V_21 ,
V_25 , F_7 ( V_19 -> V_50 ) , V_27 ,
V_20 ) ;
if ( V_22 ) {
memcpy ( V_22 , V_19 -> V_39 , F_7 ( V_19 -> V_50 ) ) ;
F_12 ( V_3 , L_24 , V_21 , V_22 ) ;
F_13 ( V_22 ) ;
}
if ( V_24 ) {
V_23 = F_14 ( V_19 -> V_39 , F_7 ( V_19 -> V_50 ) ,
V_30 | V_61 ) ;
if ( ! V_23 ) {
F_5 ( V_3 , L_25 ) ;
return - V_31 ;
}
V_26 = F_15 ( V_8 , V_24 , V_23 ,
F_7 ( V_19 -> V_50 ) ) ;
F_13 ( V_23 ) ;
if ( V_26 != 0 ) {
F_5 ( V_3 ,
L_26 ,
V_21 , V_25 ,
F_7 ( V_19 -> V_50 ) , V_27 ,
V_20 , V_26 ) ;
goto V_38;
}
}
V_9 += F_7 ( V_19 -> V_50 ) + sizeof( * V_19 ) ;
V_25 ++ ;
}
if ( V_9 > V_7 -> V_37 )
F_11 ( V_3 , L_27 ,
V_21 , V_25 , V_9 - V_7 -> V_37 ) ;
V_38:
F_16 ( V_7 ) ;
V_35:
F_13 ( V_21 ) ;
return V_26 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_8 * V_8 = V_3 -> V_8 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
const struct V_7 * V_7 ;
const char * V_20 ;
int V_26 , V_9 , V_66 , type , V_27 , V_24 ;
char * V_21 ;
void * V_23 ;
V_21 = F_3 ( V_29 , V_30 ) ;
if ( V_21 == NULL )
return - V_31 ;
snprintf ( V_21 , V_29 , L_28 , V_3 -> V_32 , V_3 -> V_33 ) ;
V_21 [ V_29 - 1 ] = '\0' ;
V_26 = F_4 ( & V_7 , V_21 , V_3 -> V_34 ) ;
if ( V_26 != 0 ) {
F_11 ( V_3 , L_2 , V_21 ) ;
V_26 = 0 ;
goto V_35;
}
V_26 = - V_36 ;
if ( sizeof( * V_63 ) >= V_7 -> V_37 ) {
F_5 ( V_3 , L_3 ,
V_21 , V_7 -> V_37 ) ;
goto V_38;
}
V_63 = ( void * ) & V_7 -> V_39 [ 0 ] ;
if ( memcmp ( V_63 -> V_40 , L_29 , 4 ) != 0 ) {
F_5 ( V_3 , L_5 , V_21 ) ;
goto V_38;
}
F_6 ( V_3 , L_30 , V_21 ,
( F_7 ( V_63 -> V_41 ) >> 16 ) & 0xff ,
( F_7 ( V_63 -> V_41 ) >> 8 ) & 0xff ,
F_7 ( V_63 -> V_41 ) & 0xff ) ;
V_9 = F_7 ( V_63 -> V_50 ) ;
V_66 = 0 ;
while ( V_9 < V_7 -> V_37 &&
V_9 - V_7 -> V_37 > sizeof( * V_65 ) ) {
V_65 = ( void * ) ( & V_7 -> V_39 [ V_9 ] ) ;
type = F_10 ( V_65 -> type ) & 0xff ;
V_27 = F_7 ( V_65 -> V_27 ) & 0xffffff ;
F_6 ( V_3 , L_31 ,
V_21 , V_66 , F_7 ( V_65 -> V_67 ) ,
( F_7 ( V_65 -> V_41 ) >> 16 ) & 0xff ,
( F_7 ( V_65 -> V_41 ) >> 8 ) & 0xff ,
F_7 ( V_65 -> V_41 ) & 0xff ) ;
F_6 ( V_3 , L_32 ,
V_21 , V_66 , F_7 ( V_65 -> V_50 ) , V_27 , type ) ;
V_24 = 0 ;
V_20 = L_13 ;
switch ( type ) {
case V_52 :
case V_53 :
break;
case V_54 :
V_20 = L_33 ;
V_24 = V_27 ;
break;
default:
F_5 ( V_3 , L_34 , type ) ;
break;
}
if ( V_24 ) {
V_23 = F_14 ( V_65 -> V_39 , F_7 ( V_65 -> V_50 ) ,
V_30 | V_61 ) ;
if ( ! V_23 ) {
F_5 ( V_3 , L_25 ) ;
return - V_31 ;
}
V_26 = F_15 ( V_8 , V_24 , V_65 -> V_39 ,
F_7 ( V_65 -> V_50 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_3 ,
L_35 ,
V_21 , V_66 , V_24 , V_20 ) ;
}
F_13 ( V_23 ) ;
}
V_9 += F_7 ( V_65 -> V_50 ) + sizeof( * V_65 ) ;
V_66 ++ ;
}
if ( V_9 > V_7 -> V_37 )
F_11 ( V_3 , L_27 ,
V_21 , V_66 , V_9 - V_7 -> V_37 ) ;
V_38:
F_16 ( V_7 ) ;
V_35:
F_13 ( V_21 ) ;
return 0 ;
}
int F_18 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
int V_72 )
{
struct V_73 * V_74 = V_69 -> V_74 ;
struct V_2 * V_75 = F_19 ( V_74 ) ;
struct V_2 * V_3 = & V_75 [ V_69 -> V_76 ] ;
int V_26 ;
switch ( V_72 ) {
case V_77 :
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_78 ,
V_79 , V_79 ) ;
V_26 = F_2 ( V_3 ) ;
if ( V_26 != 0 )
goto V_80;
V_26 = F_17 ( V_3 ) ;
if ( V_26 != 0 )
goto V_80;
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_78 ,
V_81 | V_82 ,
V_81 | V_82 ) ;
break;
case V_83 :
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_78 ,
V_81 | V_82 , 0 ) ;
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_84 ,
V_85 , 0 ) ;
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_78 ,
V_79 , 0 ) ;
break;
default:
break;
}
return 0 ;
V_80:
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_78 ,
V_79 , 0 ) ;
return V_26 ;
}
static int F_21 ( struct V_2 * V_3 )
{
unsigned int V_86 ;
int V_26 , V_87 ;
V_26 = F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_88 ,
V_89 , V_89 ) ;
if ( V_26 != 0 )
return V_26 ;
V_87 = 0 ;
do {
V_26 = F_22 ( V_3 -> V_8 , V_3 -> V_56 + V_90 ,
& V_86 ) ;
if ( V_26 != 0 )
return V_26 ;
} while ( ! ( V_86 & V_91 ) && ++ V_87 < 10 );
if ( ! ( V_86 & V_91 ) ) {
F_5 ( V_3 , L_36 ) ;
return - V_92 ;
}
F_6 ( V_3 , L_37 , V_87 ) ;
F_12 ( V_3 , L_37 , V_87 ) ;
return 0 ;
}
int F_23 ( struct V_68 * V_69 ,
struct V_70 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_69 -> V_74 ;
struct V_2 * V_75 = F_19 ( V_74 ) ;
struct V_2 * V_3 = & V_75 [ V_69 -> V_76 ] ;
unsigned int V_86 ;
int V_26 ;
switch ( V_72 ) {
case V_77 :
V_26 = F_22 ( V_3 -> V_8 , V_93 , & V_86 ) ;
if ( V_26 != 0 ) {
F_5 ( V_3 , L_38 ,
V_26 ) ;
return V_26 ;
}
V_86 = ( V_86 & V_94 )
>> V_95 ;
V_26 = F_20 ( V_3 -> V_8 ,
V_3 -> V_56 + V_96 ,
V_97 , V_86 ) ;
if ( V_26 != 0 ) {
F_5 ( V_3 , L_39 ,
V_26 ) ;
return V_26 ;
}
if ( V_3 -> V_98 ) {
V_26 = F_22 ( V_3 -> V_8 ,
V_3 -> V_56 + V_96 , & V_86 ) ;
if ( V_26 != 0 ) {
F_24 ( V_3 -> V_34 ,
L_40 , V_26 ) ;
return V_26 ;
}
if ( ( V_86 & V_97 ) >= 3 ) {
V_26 = F_25 ( V_3 -> V_98 ) ;
if ( V_26 != 0 ) {
F_24 ( V_3 -> V_34 ,
L_41 ,
V_26 ) ;
return V_26 ;
}
V_26 = F_26 ( V_3 -> V_98 ,
1800000 ,
1800000 ) ;
if ( V_26 != 0 ) {
F_24 ( V_3 -> V_34 ,
L_42 ,
V_26 ) ;
return V_26 ;
}
}
}
V_26 = F_21 ( V_3 ) ;
if ( V_26 != 0 )
return V_26 ;
V_26 = F_2 ( V_3 ) ;
if ( V_26 != 0 )
goto V_80;
V_26 = F_17 ( V_3 ) ;
if ( V_26 != 0 )
goto V_80;
V_26 = F_20 ( V_3 -> V_8 ,
V_3 -> V_56 + V_88 ,
V_99 | V_100 ,
V_99 | V_100 ) ;
if ( V_26 != 0 )
goto V_80;
break;
case V_83 :
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_88 ,
V_89 | V_99 |
V_100 , 0 ) ;
if ( V_3 -> V_98 ) {
V_26 = F_26 ( V_3 -> V_98 , 1200000 ,
1800000 ) ;
if ( V_26 != 0 )
F_27 ( V_3 -> V_34 ,
L_43 ,
V_26 ) ;
V_26 = F_28 ( V_3 -> V_98 ) ;
if ( V_26 != 0 )
F_24 ( V_3 -> V_34 ,
L_41 ,
V_26 ) ;
}
break;
default:
break;
}
return 0 ;
V_80:
F_20 ( V_3 -> V_8 , V_3 -> V_56 + V_88 ,
V_89 | V_99 | V_100 , 0 ) ;
return V_26 ;
}
int F_29 ( struct V_2 * V_101 , bool V_98 )
{
int V_26 ;
V_26 = F_20 ( V_101 -> V_8 , V_101 -> V_56 + V_88 ,
V_102 , 0 ) ;
if ( V_26 != 0 ) {
F_5 ( V_101 , L_44 , V_26 ) ;
return V_26 ;
}
if ( V_98 ) {
V_101 -> V_98 = F_30 ( V_101 -> V_34 , L_45 ) ;
if ( F_31 ( V_101 -> V_98 ) ) {
V_26 = F_32 ( V_101 -> V_98 ) ;
F_24 ( V_101 -> V_34 , L_46 , V_26 ) ;
return V_26 ;
}
V_26 = F_25 ( V_101 -> V_98 ) ;
if ( V_26 != 0 ) {
F_24 ( V_101 -> V_34 , L_47 ,
V_26 ) ;
return V_26 ;
}
V_26 = F_26 ( V_101 -> V_98 , 1200000 , 1800000 ) ;
if ( V_26 != 0 ) {
F_24 ( V_101 -> V_34 , L_48 ,
V_26 ) ;
return V_26 ;
}
V_26 = F_28 ( V_101 -> V_98 ) ;
if ( V_26 != 0 ) {
F_24 ( V_101 -> V_34 , L_49 ,
V_26 ) ;
return V_26 ;
}
}
return 0 ;
}
