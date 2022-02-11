int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
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
if ( F_15 ( V_9 -> V_17 , V_4 -> V_25 ) )
V_2 -> V_26 = V_27 ;
else
V_2 -> V_26 = V_28 ;
}
else if ( 1 ) {
if ( F_13 ( ! F_15 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_26 = V_29 ;
}
if ( F_16 ( V_4 ) )
return F_3 ( V_30 ) ;
if ( F_17 ( V_4 ) )
return F_3 ( V_31 ) ;
if ( F_8 ( V_9 -> V_13 ) >= V_32 )
return V_9 -> V_13 ;
if ( V_2 -> V_7 >= 2 && * ( unsigned short * ) ( V_2 -> V_21 ) == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_18 ( const struct V_1 * V_2 , unsigned char * V_33 )
{
const struct V_8 * V_9 = F_12 ( V_2 ) ;
memcpy ( V_33 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_19 ( const struct V_34 * V_35 , struct V_36 * V_37 , T_1 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_35 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_38 * ) V_37 -> V_39 ) + ( F_20 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_35 -> V_40 , V_16 ) ;
V_37 -> V_41 = V_10 ;
return 0 ;
}
void F_21 ( struct V_36 * V_37 ,
const struct V_3 * V_4 ,
const unsigned char * V_33 )
{
memcpy ( ( ( V_38 * ) V_37 -> V_39 ) + F_20 ( sizeof( struct V_8 ) ) ,
V_33 , V_16 ) ;
}
int F_22 ( struct V_3 * V_4 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
if ( ! ( V_4 -> V_45 & V_46 ) && F_23 ( V_4 ) )
return - V_47 ;
if ( ! F_24 ( V_44 -> V_48 ) )
return - V_49 ;
return 0 ;
}
void F_25 ( struct V_3 * V_4 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
memcpy ( V_4 -> V_14 , V_44 -> V_48 , V_16 ) ;
}
int F_26 ( struct V_3 * V_4 , void * V_42 )
{
int V_50 ;
V_50 = F_22 ( V_4 , V_42 ) ;
if ( V_50 < 0 )
return V_50 ;
F_25 ( V_4 , V_42 ) ;
return 0 ;
}
int F_27 ( struct V_3 * V_4 , int V_51 )
{
if ( V_51 < 68 || V_51 > V_52 )
return - V_53 ;
V_4 -> V_54 = V_51 ;
return 0 ;
}
int F_28 ( struct V_3 * V_4 )
{
if ( ! F_24 ( V_4 -> V_14 ) )
return - V_49 ;
return 0 ;
}
void F_29 ( struct V_3 * V_4 )
{
V_4 -> V_55 = & V_56 ;
V_4 -> type = V_57 ;
V_4 -> V_58 = V_10 ;
V_4 -> V_54 = V_52 ;
V_4 -> V_59 = V_16 ;
V_4 -> V_60 = 1000 ;
V_4 -> V_18 = V_61 | V_62 ;
V_4 -> V_45 |= V_63 ;
memset ( V_4 -> V_25 , 0xFF , V_16 ) ;
}
struct V_3 * F_30 ( int V_64 , unsigned int V_65 ,
unsigned int V_66 )
{
return F_31 ( V_64 , L_2 , F_29 , V_65 , V_66 ) ;
}
T_2 F_32 ( char * V_67 , const unsigned char * V_44 , int V_7 )
{
return F_33 ( V_67 , V_68 , L_3 , V_7 , V_44 ) ;
}
