int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) F_2 ( V_2 , V_10 ) ;
if ( type != V_11 && type != V_12 )
V_9 -> V_13 = F_3 ( type ) ;
else
V_9 -> V_13 = F_3 ( V_7 ) ;
if ( ! V_6 )
V_6 = V_4 -> V_14 ;
memcpy ( V_9 -> V_15 , V_6 , V_16 ) ;
if ( V_5 ) {
memcpy ( V_9 -> V_17 , V_5 , V_16 ) ;
return V_10 ;
}
if ( V_4 -> V_18 & ( V_19 | V_20 ) ) {
memset ( V_9 -> V_17 , 0 , V_16 ) ;
return V_10 ;
}
return - V_10 ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
switch ( V_9 -> V_13 ) {
#ifdef F_5
case F_3 ( V_22 ) :
return F_6 ( V_9 -> V_17 , V_2 ) ;
#endif
default:
F_7 ( V_23
L_1 ,
V_4 -> V_24 , F_8 ( V_9 -> V_13 ) ) ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
break;
}
return 0 ;
}
T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_10 ) ;
V_9 = F_12 ( V_2 ) ;
if ( F_13 ( F_14 ( V_9 -> V_17 ) ) ) {
if ( ! F_15 ( V_9 -> V_17 , V_4 -> V_25 ) )
V_2 -> V_26 = V_27 ;
else
V_2 -> V_26 = V_28 ;
}
else if ( 1 ) {
if ( F_13 ( F_15 ( V_9 -> V_17 , V_4 -> V_14 ) ) )
V_2 -> V_26 = V_29 ;
}
if ( F_16 ( V_4 ) )
return F_3 ( V_30 ) ;
if ( F_17 ( V_4 ) )
return F_3 ( V_31 ) ;
if ( F_8 ( V_9 -> V_13 ) >= 1536 )
return V_9 -> V_13 ;
if ( V_2 -> V_7 >= 2 && * ( unsigned short * ) ( V_2 -> V_21 ) == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_18 ( const struct V_1 * V_2 , unsigned char * V_32 )
{
const struct V_8 * V_9 = F_12 ( V_2 ) ;
memcpy ( V_32 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_19 ( const struct V_33 * V_34 , struct V_35 * V_36 , T_1 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_34 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_37 * ) V_36 -> V_38 ) + ( F_20 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_34 -> V_39 , V_16 ) ;
V_36 -> V_40 = V_10 ;
return 0 ;
}
void F_21 ( struct V_35 * V_36 ,
const struct V_3 * V_4 ,
const unsigned char * V_32 )
{
memcpy ( ( ( V_37 * ) V_36 -> V_38 ) + F_20 ( sizeof( struct V_8 ) ) ,
V_32 , V_16 ) ;
}
int F_22 ( struct V_3 * V_4 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
if ( F_23 ( V_4 ) )
return - V_44 ;
if ( ! F_24 ( V_43 -> V_45 ) )
return - V_46 ;
memcpy ( V_4 -> V_14 , V_43 -> V_45 , V_16 ) ;
V_4 -> V_47 &= ~ V_48 ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 , int V_49 )
{
if ( V_49 < 68 || V_49 > V_50 )
return - V_51 ;
V_4 -> V_52 = V_49 ;
return 0 ;
}
int F_26 ( struct V_3 * V_4 )
{
if ( ! F_24 ( V_4 -> V_14 ) )
return - V_46 ;
return 0 ;
}
void F_27 ( struct V_3 * V_4 )
{
V_4 -> V_53 = & V_54 ;
V_4 -> type = V_55 ;
V_4 -> V_56 = V_10 ;
V_4 -> V_52 = V_50 ;
V_4 -> V_57 = V_16 ;
V_4 -> V_58 = 1000 ;
V_4 -> V_18 = V_59 | V_60 ;
V_4 -> V_61 |= V_62 ;
memset ( V_4 -> V_25 , 0xFF , V_16 ) ;
}
struct V_3 * F_28 ( int V_63 , unsigned int V_64 ,
unsigned int V_65 )
{
return F_29 ( V_63 , L_2 , F_27 , V_64 , V_65 ) ;
}
static T_2 F_30 ( char * V_66 , int V_67 ,
const unsigned char * V_43 , int V_7 )
{
int V_68 ;
char * V_69 = V_66 ;
for ( V_68 = 0 ; V_68 < V_7 ; V_68 ++ ) {
V_69 += F_31 ( V_69 , V_67 - ( V_69 - V_66 ) , L_3 , V_43 [ V_68 ] ) ;
if ( V_68 == V_7 - 1 )
break;
V_69 += F_31 ( V_69 , V_67 - ( V_69 - V_66 ) , L_4 ) ;
}
return V_69 - V_66 ;
}
T_3 F_32 ( char * V_66 , const unsigned char * V_43 , int V_7 )
{
T_2 V_70 ;
V_70 = F_30 ( V_66 , V_71 , V_43 , V_7 ) ;
V_70 += F_31 ( V_66 + V_70 , V_71 - V_70 , L_5 ) ;
return ( T_3 ) V_70 ;
}
