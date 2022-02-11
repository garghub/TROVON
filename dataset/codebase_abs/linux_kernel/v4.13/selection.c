static inline void F_1 ( const int V_1 , const int V_2 )
{
F_2 ( V_3 , V_1 , V_2 - V_1 + 2 , 1 ) ;
}
static inline void F_3 ( const int V_4 )
{
F_4 ( V_3 , V_4 ) ;
}
static T_1
F_5 ( int V_5 )
{
return F_6 ( V_3 , F_7 ( V_3 , V_5 ) ,
V_6 ) ;
}
void F_8 ( void )
{
F_3 ( - 1 ) ;
if ( V_7 != - 1 ) {
F_1 ( V_7 , V_8 ) ;
V_7 = - 1 ;
}
}
static inline int F_9 ( const T_1 V_9 ) {
return V_9 > 0x7f || ( ( V_10 [ V_9 >> 5 ] >> ( V_9 & 0x1F ) ) & 1 ) ;
}
int F_10 ( char T_2 * V_11 )
{
T_3 V_12 [ F_11 ( V_10 ) ] ;
if ( F_12 ( V_12 , ( T_3 T_2 * ) ( V_11 + 4 ) , sizeof( V_10 ) ) )
return - V_13 ;
memcpy ( V_10 , V_12 , sizeof( V_10 ) ) ;
return 0 ;
}
static inline int F_13 ( const int V_11 , int V_14 )
{
return ( ! ( V_11 % V_14 ) || ! ( ( V_11 + 2 ) % V_14 ) ) ;
}
static inline unsigned short F_14 ( const unsigned short V_15 , const unsigned short V_16 )
{
return ( V_15 > V_16 ) ? V_16 : V_15 ;
}
static int F_15 ( T_1 V_9 , char * V_11 )
{
if ( V_9 < 0x80 ) {
V_11 [ 0 ] = V_9 ;
return 1 ;
} else if ( V_9 < 0x800 ) {
V_11 [ 0 ] = 0xc0 | ( V_9 >> 6 ) ;
V_11 [ 1 ] = 0x80 | ( V_9 & 0x3f ) ;
return 2 ;
} else {
V_11 [ 0 ] = 0xe0 | ( V_9 >> 12 ) ;
V_11 [ 1 ] = 0x80 | ( ( V_9 >> 6 ) & 0x3f ) ;
V_11 [ 2 ] = 0x80 | ( V_9 & 0x3f ) ;
return 3 ;
}
}
int F_16 ( const struct V_17 T_2 * V_18 , struct V_19 * V_20 )
{
struct V_21 * V_22 = V_23 [ V_24 ] . V_25 ;
int V_26 , V_27 , V_28 , V_29 ;
char * V_30 , * V_31 ;
int V_32 , V_33 , V_34 , V_35 ;
T_1 V_9 ;
int V_36 ;
F_17 () ;
{ unsigned short V_37 , V_38 , V_39 , V_40 ;
if ( ! F_18 ( V_41 , V_18 , sizeof( * V_18 ) ) )
return - V_13 ;
F_19 ( V_37 , & V_18 -> V_37 ) ;
F_19 ( V_38 , & V_18 -> V_38 ) ;
F_19 ( V_39 , & V_18 -> V_39 ) ;
F_19 ( V_40 , & V_18 -> V_40 ) ;
F_19 ( V_26 , & V_18 -> V_26 ) ;
V_37 -- ; V_38 -- ; V_39 -- ; V_40 -- ;
V_37 = F_14 ( V_37 , V_22 -> V_42 - 1 ) ;
V_38 = F_14 ( V_38 , V_22 -> V_43 - 1 ) ;
V_39 = F_14 ( V_39 , V_22 -> V_42 - 1 ) ;
V_40 = F_14 ( V_40 , V_22 -> V_43 - 1 ) ;
V_33 = V_38 * V_22 -> V_44 + ( V_37 << 1 ) ;
V_34 = V_40 * V_22 -> V_44 + ( V_39 << 1 ) ;
if ( V_26 == V_45 ) {
F_8 () ;
return 0 ;
}
if ( F_20 () && ( V_26 & V_46 ) ) {
F_21 ( V_20 , V_26 & V_47 , V_37 , V_38 ) ;
return 0 ;
}
}
if ( V_33 > V_34 )
{
int V_48 = V_33 ;
V_33 = V_34 ;
V_34 = V_48 ;
}
if ( V_3 != V_23 [ V_24 ] . V_25 ) {
F_8 () ;
V_3 = V_23 [ V_24 ] . V_25 ;
}
V_36 = F_22 ( V_24 ) ;
if ( V_36 == V_49 )
V_6 = 1 ;
else
V_6 = 0 ;
switch ( V_26 )
{
case V_50 :
V_27 = V_33 ;
V_28 = V_34 ;
break;
case V_51 :
V_29 = isspace ( F_5 ( V_33 ) ) ;
for ( V_27 = V_33 ; ; V_33 -= 2 )
{
if ( ( V_29 && ! isspace ( F_5 ( V_33 ) ) ) ||
( ! V_29 && ! F_9 ( F_5 ( V_33 ) ) ) )
break;
V_27 = V_33 ;
if ( ! ( V_33 % V_22 -> V_44 ) )
break;
}
V_29 = isspace ( F_5 ( V_34 ) ) ;
for ( V_28 = V_34 ; ; V_34 += 2 )
{
if ( ( V_29 && ! isspace ( F_5 ( V_34 ) ) ) ||
( ! V_29 && ! F_9 ( F_5 ( V_34 ) ) ) )
break;
V_28 = V_34 ;
if ( ! ( ( V_34 + 2 ) % V_22 -> V_44 ) )
break;
}
break;
case V_52 :
V_27 = V_33 - V_33 % V_22 -> V_44 ;
V_28 = V_34 + V_22 -> V_44
- V_34 % V_22 -> V_44 - 2 ;
break;
case V_53 :
F_3 ( V_34 ) ;
return 0 ;
default:
return - V_54 ;
}
F_3 ( - 1 ) ;
if ( V_28 > V_27 &&
! F_13 ( V_28 , V_22 -> V_44 ) &&
isspace ( F_5 ( V_28 ) ) ) {
for ( V_34 = V_28 + 2 ; ; V_34 += 2 )
if ( ! isspace ( F_5 ( V_34 ) ) ||
F_13 ( V_34 , V_22 -> V_44 ) )
break;
if ( isspace ( F_5 ( V_34 ) ) )
V_28 = V_34 ;
}
if ( V_7 == - 1 )
F_1 ( V_27 , V_28 ) ;
else if ( V_27 == V_7 )
{
if ( V_28 == V_8 )
return 0 ;
else if ( V_28 > V_8 )
F_1 ( V_8 + 2 , V_28 ) ;
else
F_1 ( V_28 + 2 , V_8 ) ;
}
else if ( V_28 == V_8 )
{
if ( V_27 < V_7 )
F_1 ( V_27 , V_7 - 2 ) ;
else
F_1 ( V_7 , V_27 - 2 ) ;
}
else
{
F_8 () ;
F_1 ( V_27 , V_28 ) ;
}
V_7 = V_27 ;
V_8 = V_28 ;
V_35 = V_6 ? 3 : 1 ;
V_30 = F_23 ( ( ( V_8 - V_7 ) / 2 + 1 ) * V_35 , V_55 ) ;
if ( ! V_30 ) {
F_24 ( V_56 L_1 ) ;
F_8 () ;
return - V_57 ;
}
F_25 ( V_58 ) ;
V_58 = V_30 ;
V_31 = V_30 ;
for ( V_32 = V_7 ; V_32 <= V_8 ; V_32 += 2 ) {
V_9 = F_5 ( V_32 ) ;
if ( V_6 )
V_30 += F_15 ( V_9 , V_30 ) ;
else
* V_30 ++ = V_9 ;
if ( ! isspace ( V_9 ) )
V_31 = V_30 ;
if ( ! ( ( V_32 + 2 ) % V_22 -> V_44 ) ) {
if ( V_31 != V_30 ) {
V_30 = V_31 ;
* V_30 ++ = '\r' ;
}
V_31 = V_30 ;
}
}
V_59 = V_30 - V_58 ;
return 0 ;
}
int F_26 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_60 ;
int V_61 = 0 ;
unsigned int V_62 ;
struct V_63 * V_64 ;
F_27 ( V_65 , V_66 ) ;
F_28 () ;
F_17 () ;
F_29 () ;
V_64 = F_30 ( V_20 ) ;
if ( ! V_64 )
return - V_67 ;
F_31 ( & V_22 -> V_68 ) ;
F_32 ( & V_22 -> V_69 , & V_65 ) ;
while ( V_58 && V_59 > V_61 ) {
F_33 ( V_70 ) ;
if ( F_34 ( V_20 ) ) {
F_35 () ;
continue;
}
F_36 ( V_71 ) ;
V_62 = V_59 - V_61 ;
V_62 = F_37 ( V_64 , V_58 + V_61 , NULL ,
V_62 ) ;
V_61 += V_62 ;
}
F_38 ( & V_22 -> V_69 , & V_65 ) ;
F_36 ( V_71 ) ;
F_39 ( & V_22 -> V_68 ) ;
F_40 ( V_64 ) ;
return 0 ;
}
