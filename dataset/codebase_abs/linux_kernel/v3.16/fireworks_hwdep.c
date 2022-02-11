static long
F_1 ( struct V_1 * V_2 , char T_1 * V_3 , long V_4 ,
T_2 * V_5 )
{
unsigned int V_6 , V_7 , type ;
struct V_8 * V_9 ;
long V_10 = 0 ;
if ( V_4 < sizeof( type ) + sizeof( struct V_8 ) )
return - V_11 ;
type = V_12 ;
if ( F_2 ( V_3 , & type , sizeof( type ) ) )
return - V_13 ;
V_4 -= sizeof( type ) ;
V_3 += sizeof( type ) ;
while ( V_2 -> V_14 > 0 ) {
V_9 = (struct V_8 * ) ( V_2 -> V_15 ) ;
V_6 = F_3 ( V_9 -> V_6 ) * sizeof( V_16 ) ;
if ( V_4 < V_6 )
break;
while ( V_6 > 0 ) {
V_7 = V_17 -
( unsigned int ) ( V_2 -> V_15 - V_2 -> V_18 ) ;
V_7 = F_4 (unsigned int, length, till_end) ;
if ( F_2 ( V_3 , V_2 -> V_15 , V_7 ) )
return - V_13 ;
V_2 -> V_15 += V_7 ;
if ( V_2 -> V_15 >= V_2 -> V_18 +
V_17 )
V_2 -> V_15 -= V_17 ;
V_6 -= V_7 ;
V_3 += V_7 ;
V_10 += V_7 ;
V_4 -= V_7 ;
}
V_2 -> V_14 -- ;
}
return V_10 ;
}
static long
F_5 ( struct V_1 * V_2 , char T_1 * V_3 , long V_10 ,
T_2 * V_5 )
{
union V_19 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_21 . type = V_22 ;
V_20 . V_21 . V_23 = ( V_2 -> V_24 > 0 ) ;
V_2 -> V_25 = false ;
V_10 = F_4 ( long , V_10 , sizeof( V_20 . V_21 ) ) ;
if ( F_2 ( V_3 , & V_20 , V_10 ) )
return - V_13 ;
return V_10 ;
}
static long
F_6 ( struct V_26 * V_27 , char T_1 * V_3 , long V_10 ,
T_2 * V_5 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_7 ( V_29 ) ;
F_8 ( & V_2 -> V_30 ) ;
while ( ( ! V_2 -> V_25 ) && ( V_2 -> V_14 == 0 ) ) {
F_9 ( & V_2 -> V_31 , & V_29 , V_32 ) ;
F_10 ( & V_2 -> V_30 ) ;
F_11 () ;
F_12 ( & V_2 -> V_31 , & V_29 ) ;
if ( F_13 ( V_33 ) )
return - V_34 ;
F_8 ( & V_2 -> V_30 ) ;
}
if ( V_2 -> V_25 )
V_10 = F_5 ( V_2 , V_3 , V_10 , V_5 ) ;
else if ( V_2 -> V_14 > 0 )
V_10 = F_1 ( V_2 , V_3 , V_10 , V_5 ) ;
F_10 ( & V_2 -> V_30 ) ;
return V_10 ;
}
static long
F_14 ( struct V_26 * V_27 , const char T_1 * V_35 , long V_10 ,
T_2 * V_5 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
T_3 V_36 ;
T_4 * V_3 ;
if ( V_10 < sizeof( struct V_8 ) ||
V_37 < V_10 )
return - V_38 ;
V_3 = F_15 ( V_35 , V_10 ) ;
if ( F_16 ( V_3 ) )
return F_17 ( V_3 ) ;
V_36 = F_3 ( ( (struct V_8 * ) V_3 ) -> V_36 ) ;
if ( V_36 > V_39 ) {
V_10 = - V_38 ;
goto V_40;
}
if ( F_18 ( V_2 -> V_41 , V_3 , V_10 ) < 0 )
V_10 = - V_42 ;
V_40:
F_19 ( V_3 ) ;
return V_10 ;
}
static unsigned int
F_20 ( struct V_26 * V_27 , struct V_43 * V_43 , T_5 * V_29 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
unsigned int V_44 ;
F_21 ( V_43 , & V_2 -> V_31 , V_29 ) ;
F_8 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_25 || ( V_2 -> V_14 > 0 ) )
V_44 = V_45 | V_46 ;
else
V_44 = 0 ;
F_10 ( & V_2 -> V_30 ) ;
return V_44 | V_47 ;
}
static int
F_22 ( struct V_1 * V_2 , void T_1 * V_48 )
{
struct V_49 * V_50 = F_23 ( V_2 -> V_41 ) ;
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . type = V_53 ;
V_52 . V_54 = V_50 -> V_54 -> V_55 ;
* ( V_16 * ) & V_52 . V_56 [ 0 ] = F_24 ( V_50 -> V_57 [ 3 ] ) ;
* ( V_16 * ) & V_52 . V_56 [ 4 ] = F_24 ( V_50 -> V_57 [ 4 ] ) ;
F_25 ( V_52 . V_58 , F_26 ( & V_50 -> V_59 ) ,
sizeof( V_52 . V_58 ) ) ;
if ( F_2 ( V_48 , & V_52 , sizeof( V_52 ) ) )
return - V_13 ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
int V_60 ;
F_8 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_24 == 0 ) {
V_2 -> V_24 = - 1 ;
V_60 = 0 ;
} else {
V_60 = - V_61 ;
}
F_10 ( & V_2 -> V_30 ) ;
return V_60 ;
}
static int
F_28 ( struct V_1 * V_2 )
{
int V_60 ;
F_8 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_24 == - 1 ) {
V_2 -> V_24 = 0 ;
V_60 = 0 ;
} else {
V_60 = - V_62 ;
}
F_10 ( & V_2 -> V_30 ) ;
return V_60 ;
}
static int
F_29 ( struct V_26 * V_27 , struct V_43 * V_43 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_8 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_24 == - 1 )
V_2 -> V_24 = 0 ;
F_10 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int
F_30 ( struct V_26 * V_27 , struct V_43 * V_43 ,
unsigned int V_63 , unsigned long V_48 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
switch ( V_63 ) {
case V_64 :
return F_22 ( V_2 , ( void T_1 * ) V_48 ) ;
case V_65 :
return F_27 ( V_2 ) ;
case V_66 :
return F_28 ( V_2 ) ;
default:
return - V_67 ;
}
}
static int
F_31 ( struct V_26 * V_27 , struct V_43 * V_43 ,
unsigned int V_63 , unsigned long V_48 )
{
return F_30 ( V_27 , V_43 , V_63 ,
( unsigned long ) F_32 ( V_48 ) ) ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_60 ;
V_60 = F_34 ( V_2 -> V_54 , L_1 , 0 , & V_27 ) ;
if ( V_60 < 0 )
goto V_40;
strcpy ( V_27 -> V_68 , L_1 ) ;
V_27 -> V_69 = V_70 ;
V_27 -> V_71 = V_72 ;
V_27 -> V_28 = V_2 ;
V_27 -> V_73 = true ;
V_40:
return V_60 ;
}
