int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
T_1 F_3 ( const char * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
int V_5 ;
V_3 = 0 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_3 <<= 8 ;
if ( * V_2 != '\0' ) {
V_4 = 0 ;
while ( * V_2 != '\0' && * V_2 != '.' && * V_2 != '\n' ) {
V_4 *= 10 ;
V_4 += * V_2 - '0' ;
V_2 ++ ;
}
V_3 |= V_4 ;
if ( * V_2 != '\0' )
V_2 ++ ;
}
}
return F_4 ( V_3 ) ;
}
static inline int F_5 ( char V_6 , int V_7 )
{
int V_4 ;
if ( V_6 == V_7 || V_6 == '\0' )
return V_8 ;
if ( V_6 == ':' )
return V_9 ;
if ( V_6 == '.' )
return V_10 ;
V_4 = F_6 ( V_6 ) ;
if ( V_4 >= 0 )
return V_4 | V_11 | ( V_4 < 10 ? V_12 : 0 ) ;
if ( V_7 == - 1 )
return V_8 ;
return V_13 ;
}
int F_7 ( const char * V_14 , int V_15 ,
T_2 * V_16 ,
int V_7 , const char * * V_17 )
{
const char * V_18 ;
T_2 * V_19 ;
T_2 V_20 [ 4 ] ;
int V_21 = 0 ;
int V_5 ;
int V_22 = 0 ;
if ( V_15 < 0 )
V_15 = strlen ( V_14 ) ;
V_18 = V_14 ;
V_19 = V_20 ;
V_5 = 0 ;
while ( 1 ) {
int V_6 ;
V_6 = F_5 ( V_15 > 0 ? * V_18 : '\0' , V_7 ) ;
if ( ! ( V_6 & ( V_12 | V_10 | V_8 | V_9 ) ) ) {
goto V_23;
}
if ( V_6 & ( V_10 | V_8 | V_9 ) ) {
if ( V_22 == 0 )
goto V_23;
* V_19 ++ = V_22 & 0xff ;
V_22 = 0 ;
V_5 ++ ;
if ( V_6 & ( V_8 | V_9 ) ) {
if ( V_5 != 4 )
goto V_23;
break;
}
goto V_24;
}
V_22 = ( V_22 * 10 ) + V_6 ;
if ( ( V_22 & 0xffff ) > 255 ) {
goto V_23;
}
V_24:
if ( V_5 >= 4 )
goto V_23;
V_18 ++ ;
V_15 -- ;
}
V_21 = 1 ;
memcpy ( V_16 , V_20 , sizeof( V_20 ) ) ;
V_23:
if ( V_17 )
* V_17 = V_18 ;
return V_21 ;
}
int F_8 ( const char * V_14 , int V_15 ,
T_2 * V_16 ,
int V_7 , const char * * V_17 )
{
const char * V_18 , * V_25 = NULL ;
T_2 * V_19 , * V_26 = NULL ;
T_2 V_20 [ 16 ] ;
int V_21 = 0 ;
int V_5 ;
int V_27 = V_28 | V_11 | V_29 ;
int V_22 = 0 ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
V_18 = V_14 ;
V_19 = V_20 ;
if ( V_15 < 0 )
V_15 = strlen ( V_14 ) ;
while ( 1 ) {
int V_6 ;
V_6 = F_5 ( V_15 > 0 ? * V_18 : '\0' , V_7 ) ;
if ( ! ( V_6 & V_27 ) )
goto V_23;
if ( V_6 & ( V_8 | V_9 ) ) {
if ( ! ( V_27 & V_29 ) ) {
* V_19 ++ = ( V_22 >> 8 ) & 0xff ;
* V_19 ++ = V_22 & 0xff ;
}
V_22 = 0 ;
if ( V_6 & V_8 ) {
break;
}
switch ( V_27 & V_9 ) {
case V_30 :
V_26 = V_19 ;
V_27 = V_11 | V_8 ;
if ( V_26 - V_20 >= sizeof( V_20 ) )
V_27 |= V_29 ;
break;
case V_31 | V_28 :
V_27 = V_11 | V_30 ;
break;
case V_31 :
V_27 = V_11 ;
break;
case V_28 :
V_27 = V_30 ;
break;
default:
V_27 = 0 ;
}
V_25 = V_18 + 1 ;
goto V_24;
}
if ( V_6 & V_10 ) {
V_21 = F_7 ( V_25 ? V_25 : V_18 , V_15 + ( int ) ( V_18 - V_25 ) , V_19 , V_7 , & V_18 ) ;
if ( V_21 > 0 ) {
V_19 += 4 ;
break;
}
goto V_23;
}
V_22 = ( V_22 << 4 ) | ( 0xff & V_6 ) ;
V_27 = V_31 | V_8 ;
if ( ! ( V_22 & 0xf000 ) ) {
V_27 |= V_11 ;
}
if ( ! V_26 && V_19 + 2 < V_20 + sizeof( V_20 ) ) {
V_27 |= V_28 ;
V_27 &= ~ V_8 ;
}
if ( V_19 + 2 >= V_20 + sizeof( V_20 ) ) {
V_27 &= ~ ( V_31 | V_28 ) ;
}
V_24:
if ( ( V_26 && V_19 + 4 < V_20 + sizeof( V_20 ) ) ||
V_19 + 4 == V_20 + sizeof( V_20 ) ) {
V_27 |= V_10 ;
}
if ( V_19 >= V_20 + sizeof( V_20 ) ) {
V_27 &= ~ ( V_11 | V_9 ) ;
}
V_18 ++ ;
V_15 -- ;
}
V_5 = 15 ; V_19 -- ;
if ( V_26 ) {
while ( V_19 >= V_26 )
V_16 [ V_5 -- ] = * V_19 -- ;
while ( V_5 >= V_26 - V_20 )
V_16 [ V_5 -- ] = 0 ;
while ( V_5 >= 0 )
V_16 [ V_5 -- ] = * V_19 -- ;
} else
memcpy ( V_16 , V_20 , sizeof( V_20 ) ) ;
V_21 = 1 ;
V_23:
if ( V_17 )
* V_17 = V_18 ;
return V_21 ;
}
static int F_9 ( const char * V_14 , T_3 V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
int V_15 = strlen ( V_14 ) ;
if ( V_15 > V_37 )
return - V_38 ;
if ( F_7 ( V_14 , V_15 , ( T_2 * ) & V_36 -> V_39 . V_40 ,
'\n' , NULL ) == 0 )
return - V_38 ;
V_36 -> V_41 = V_42 ;
V_36 -> V_43 = F_10 ( V_32 ) ;
return 0 ;
}
static int F_11 ( struct V_44 * V_44 , const char * V_14 , T_3 V_32 ,
struct V_33 * V_34 )
{
struct V_45 * V_46 = (struct V_45 * ) V_34 ;
const char * V_47 ;
int V_15 = strlen ( V_14 ) ;
if ( V_15 > V_48 )
return - V_38 ;
if ( F_8 ( V_14 , V_15 , ( T_2 * ) & V_46 -> V_49 . V_50 ,
'%' , & V_47 ) == 0 )
return - V_38 ;
if ( F_12 ( & V_46 -> V_49 ) & V_51 &&
V_14 + V_15 != V_47 && * V_47 == '%' ) {
struct V_52 * V_53 ;
char V_54 [ 16 ] ;
T_4 V_55 = F_13 ( T_4 , sizeof( V_54 ) - 1 ,
V_14 + V_15 - V_47 - 1 ) ;
memcpy ( V_54 , V_47 + 1 , V_55 ) ;
V_54 [ V_55 ] = '\0' ;
V_53 = F_14 ( V_44 , V_54 ) ;
if ( V_53 ) {
V_46 -> V_56 = V_53 -> V_57 ;
F_15 ( V_53 ) ;
} else if ( F_16 ( V_54 , 0 , & V_46 -> V_56 ) ) {
return - V_38 ;
}
}
V_46 -> V_58 = V_59 ;
V_46 -> V_60 = F_10 ( V_32 ) ;
return 0 ;
}
int F_17 ( struct V_44 * V_44 , T_5 V_61 ,
const char * V_14 , const char * V_62 , struct V_33 * V_34 )
{
T_3 V_32 ;
int V_21 = - V_38 ;
if ( V_62 ) {
if ( F_18 ( V_62 , 0 , & V_32 ) )
return - V_38 ;
} else {
V_32 = 0 ;
}
switch ( V_61 ) {
case V_42 :
V_21 = F_9 ( V_14 , V_32 , V_34 ) ;
break;
case V_59 :
V_21 = F_11 ( V_44 , V_14 , V_32 , V_34 ) ;
break;
case V_63 :
V_21 = F_9 ( V_14 , V_32 , V_34 ) ;
if ( V_21 )
V_21 = F_11 ( V_44 , V_14 , V_32 , V_34 ) ;
break;
default:
F_19 ( L_1 , V_61 ) ;
} ;
return V_21 ;
}
void F_20 ( T_6 * V_64 , struct V_65 * V_66 ,
T_1 V_67 , T_1 V_68 , bool V_69 )
{
if ( V_66 -> V_70 != V_71 ) {
F_21 ( V_64 , V_67 , V_68 ) ;
if ( V_66 -> V_70 == V_72 && V_69 )
V_66 -> V_73 = ~ F_22 ( F_23 ( ~ ( V_66 -> V_73 ) ,
( V_74 V_75 ) V_67 ) ,
( V_74 V_75 ) V_68 ) ;
} else if ( V_69 )
* V_64 = ~ F_24 ( F_22 ( F_23 ( F_25 ( * V_64 ) ,
( V_74 V_75 ) V_67 ) ,
( V_74 V_75 ) V_68 ) ) ;
}
void F_26 ( T_6 * V_64 , struct V_65 * V_66 ,
const T_1 * V_67 , const T_1 * V_68 ,
bool V_69 )
{
T_1 V_76 [] = {
~ V_67 [ 0 ] , ~ V_67 [ 1 ] , ~ V_67 [ 2 ] , ~ V_67 [ 3 ] ,
V_68 [ 0 ] , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] ,
} ;
if ( V_66 -> V_70 != V_71 ) {
* V_64 = F_24 ( F_27 ( V_76 , sizeof( V_76 ) ,
~ F_25 ( * V_64 ) ) ) ;
if ( V_66 -> V_70 == V_72 && V_69 )
V_66 -> V_73 = ~ F_27 ( V_76 , sizeof( V_76 ) ,
~ V_66 -> V_73 ) ;
} else if ( V_69 )
* V_64 = ~ F_24 ( F_27 ( V_76 , sizeof( V_76 ) ,
F_25 ( * V_64 ) ) ) ;
}
void F_28 ( T_6 * V_64 , struct V_65 * V_66 ,
V_75 V_76 , bool V_69 )
{
if ( V_66 -> V_70 != V_71 ) {
* V_64 = F_24 ( F_22 ( V_76 , ~ F_25 ( * V_64 ) ) ) ;
if ( V_66 -> V_70 == V_72 && V_69 )
V_66 -> V_73 = ~ F_22 ( V_76 , ~ V_66 -> V_73 ) ;
} else if ( V_69 ) {
* V_64 = ~ F_24 ( F_22 ( V_76 , F_25 ( * V_64 ) ) ) ;
}
}
