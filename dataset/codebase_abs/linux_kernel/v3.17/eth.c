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
unsigned short V_24 ;
const unsigned short * V_25 ;
const struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_10 ) ;
V_9 = F_12 ( V_2 ) ;
if ( F_13 ( F_14 ( V_9 -> V_17 ) ) ) {
if ( F_15 ( V_9 -> V_17 , V_4 -> V_26 ) )
V_2 -> V_27 = V_28 ;
else
V_2 -> V_27 = V_29 ;
}
else if ( F_13 ( ! F_15 ( V_9 -> V_17 ,
V_4 -> V_14 ) ) )
V_2 -> V_27 = V_30 ;
if ( F_13 ( F_16 ( V_4 ) ) )
return F_3 ( V_31 ) ;
if ( F_13 ( F_17 ( V_4 ) ) )
return F_3 ( V_32 ) ;
if ( F_18 ( F_8 ( V_9 -> V_13 ) >= V_33 ) )
return V_9 -> V_13 ;
V_25 = F_19 ( V_2 , 0 , sizeof( * V_25 ) , & V_24 ) ;
if ( V_25 && * V_25 == 0xFFFF )
return F_3 ( V_11 ) ;
return F_3 ( V_12 ) ;
}
int F_20 ( const struct V_1 * V_2 , unsigned char * V_34 )
{
const struct V_8 * V_9 = F_12 ( V_2 ) ;
memcpy ( V_34 , V_9 -> V_15 , V_16 ) ;
return V_16 ;
}
int F_21 ( const struct V_35 * V_36 , struct V_37 * V_38 , T_1 type )
{
struct V_8 * V_9 ;
const struct V_3 * V_4 = V_36 -> V_4 ;
V_9 = (struct V_8 * )
( ( ( V_39 * ) V_38 -> V_40 ) + ( F_22 ( sizeof( * V_9 ) ) ) ) ;
if ( type == F_3 ( V_11 ) )
return - 1 ;
V_9 -> V_13 = type ;
memcpy ( V_9 -> V_15 , V_4 -> V_14 , V_16 ) ;
memcpy ( V_9 -> V_17 , V_36 -> V_41 , V_16 ) ;
V_38 -> V_42 = V_10 ;
return 0 ;
}
void F_23 ( struct V_37 * V_38 ,
const struct V_3 * V_4 ,
const unsigned char * V_34 )
{
memcpy ( ( ( V_39 * ) V_38 -> V_40 ) + F_22 ( sizeof( struct V_8 ) ) ,
V_34 , V_16 ) ;
}
int F_24 ( struct V_3 * V_4 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
if ( ! ( V_4 -> V_46 & V_47 ) && F_25 ( V_4 ) )
return - V_48 ;
if ( ! F_26 ( V_45 -> V_49 ) )
return - V_50 ;
return 0 ;
}
void F_27 ( struct V_3 * V_4 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
memcpy ( V_4 -> V_14 , V_45 -> V_49 , V_16 ) ;
}
int F_28 ( struct V_3 * V_4 , void * V_43 )
{
int V_51 ;
V_51 = F_24 ( V_4 , V_43 ) ;
if ( V_51 < 0 )
return V_51 ;
F_27 ( V_4 , V_43 ) ;
return 0 ;
}
int F_29 ( struct V_3 * V_4 , int V_52 )
{
if ( V_52 < 68 || V_52 > V_53 )
return - V_54 ;
V_4 -> V_55 = V_52 ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 )
{
if ( ! F_26 ( V_4 -> V_14 ) )
return - V_50 ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
V_4 -> V_56 = & V_57 ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_10 ;
V_4 -> V_55 = V_53 ;
V_4 -> V_60 = V_16 ;
V_4 -> V_61 = 1000 ;
V_4 -> V_18 = V_62 | V_63 ;
V_4 -> V_46 |= V_64 ;
memset ( V_4 -> V_26 , 0xFF , V_16 ) ;
}
struct V_3 * F_32 ( int V_65 , unsigned int V_66 ,
unsigned int V_67 )
{
return F_33 ( V_65 , L_2 , V_68 ,
F_31 , V_66 , V_67 ) ;
}
T_2 F_34 ( char * V_69 , const unsigned char * V_45 , int V_7 )
{
return F_35 ( V_69 , V_70 , L_3 , V_7 , V_45 ) ;
}
