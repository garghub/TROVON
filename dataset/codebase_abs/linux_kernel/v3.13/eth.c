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
F_7 ( V_4 ,
L_1 ,
V_4 -> V_23 , F_8 ( V_9 -> V_13 ) ) ;
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
if ( F_15 ( V_9 -> V_17 , V_4 -> V_24 ) )
V_2 -> V_25 = V_26 ;
else
V_2 -> V_25 = V_27 ;
}
else if ( F_13 ( ! F_15 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_25 = V_28 ;
if ( F_13 ( F_16 ( V_4 ) ) )
return F_3 ( V_29 ) ;
if ( F_13 ( F_17 ( V_4 ) ) )
return F_3 ( V_30 ) ;
if ( F_18 ( F_8 ( V_9 -> V_13 ) >= V_31 ) )
return V_9 -> V_13 ;
if ( F_13 ( V_2 -> V_7 >= 2 && * ( unsigned short * ) ( V_2 -> V_21 ) == 0xFFFF ) )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_19 ( const struct V_1 * V_2 , unsigned char * V_32 )
{
const struct V_8 * V_9 = F_12 ( V_2 ) ;
memcpy ( V_32 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_20 ( const struct V_33 * V_34 , struct V_35 * V_36 , T_1 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_34 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_37 * ) V_36 -> V_38 ) + ( F_21 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_34 -> V_39 , V_16 ) ;
V_36 -> V_40 = V_10 ;
return 0 ;
}
void F_22 ( struct V_35 * V_36 ,
const struct V_3 * V_4 ,
const unsigned char * V_32 )
{
memcpy ( ( ( V_37 * ) V_36 -> V_38 ) + F_21 ( sizeof( struct V_8 ) ) ,
V_32 , V_16 ) ;
}
int F_23 ( struct V_3 * V_4 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
if ( ! ( V_4 -> V_44 & V_45 ) && F_24 ( V_4 ) )
return - V_46 ;
if ( ! F_25 ( V_43 -> V_47 ) )
return - V_48 ;
return 0 ;
}
void F_26 ( struct V_3 * V_4 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
memcpy ( V_4 -> V_14 , V_43 -> V_47 , V_16 ) ;
}
int F_27 ( struct V_3 * V_4 , void * V_41 )
{
int V_49 ;
V_49 = F_23 ( V_4 , V_41 ) ;
if ( V_49 < 0 )
return V_49 ;
F_26 ( V_4 , V_41 ) ;
return 0 ;
}
int F_28 ( struct V_3 * V_4 , int V_50 )
{
if ( V_50 < 68 || V_50 > V_51 )
return - V_52 ;
V_4 -> V_53 = V_50 ;
return 0 ;
}
int F_29 ( struct V_3 * V_4 )
{
if ( ! F_25 ( V_4 -> V_14 ) )
return - V_48 ;
return 0 ;
}
void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_54 = & V_55 ;
V_4 -> type = V_56 ;
V_4 -> V_57 = V_10 ;
V_4 -> V_53 = V_51 ;
V_4 -> V_58 = V_16 ;
V_4 -> V_59 = 1000 ;
V_4 -> V_18 = V_60 | V_61 ;
V_4 -> V_44 |= V_62 ;
memset ( V_4 -> V_24 , 0xFF , V_16 ) ;
}
struct V_3 * F_31 ( int V_63 , unsigned int V_64 ,
unsigned int V_65 )
{
return F_32 ( V_63 , L_2 , F_30 , V_64 , V_65 ) ;
}
T_2 F_33 ( char * V_66 , const unsigned char * V_43 , int V_7 )
{
return F_34 ( V_66 , V_67 , L_3 , V_7 , V_43 ) ;
}
