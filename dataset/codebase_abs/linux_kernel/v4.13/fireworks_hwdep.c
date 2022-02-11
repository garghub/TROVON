static long
F_1 ( struct V_1 * V_2 , char T_1 * V_3 , long V_4 ,
T_2 * V_5 )
{
unsigned int V_6 , V_7 , type ;
struct V_8 * V_9 ;
T_3 * V_10 ;
long V_11 = 0 ;
if ( V_4 < sizeof( type ) + sizeof( struct V_8 ) )
return - V_12 ;
type = V_13 ;
if ( F_2 ( V_3 , & type , sizeof( type ) ) )
return - V_14 ;
V_4 -= sizeof( type ) ;
V_3 += sizeof( type ) ;
F_3 ( & V_2 -> V_15 ) ;
V_10 = V_2 -> V_10 ;
while ( V_2 -> V_16 != V_10 ) {
V_9 = (struct V_8 * ) ( V_10 ) ;
V_6 = F_4 ( V_9 -> V_6 ) * sizeof( V_17 ) ;
if ( V_4 < V_6 )
break;
while ( V_6 > 0 ) {
V_7 = V_18 -
( unsigned int ) ( V_10 - V_2 -> V_19 ) ;
V_7 = F_5 (unsigned int, length, till_end) ;
F_6 ( & V_2 -> V_15 ) ;
if ( F_2 ( V_3 , V_10 , V_7 ) )
return - V_14 ;
F_3 ( & V_2 -> V_15 ) ;
V_10 += V_7 ;
if ( V_10 >= V_2 -> V_19 + V_18 )
V_10 -= V_18 ;
V_6 -= V_7 ;
V_3 += V_7 ;
V_11 += V_7 ;
V_4 -= V_7 ;
}
}
V_2 -> V_10 = V_10 ;
F_6 ( & V_2 -> V_15 ) ;
return V_11 ;
}
static long
F_7 ( struct V_1 * V_2 , char T_1 * V_3 , long V_11 ,
T_2 * V_5 )
{
union V_20 V_21 = {
. V_22 . type = V_23 ,
} ;
F_3 ( & V_2 -> V_15 ) ;
V_21 . V_22 . V_24 = ( V_2 -> V_25 > 0 ) ;
V_2 -> V_26 = false ;
F_6 ( & V_2 -> V_15 ) ;
V_11 = F_5 ( long , V_11 , sizeof( V_21 . V_22 ) ) ;
if ( F_2 ( V_3 , & V_21 , V_11 ) )
return - V_14 ;
return V_11 ;
}
static long
F_8 ( struct V_27 * V_28 , char T_1 * V_3 , long V_11 ,
T_2 * V_5 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
F_9 ( V_30 ) ;
bool V_26 ;
bool V_31 ;
F_3 ( & V_2 -> V_15 ) ;
V_26 = V_2 -> V_26 ;
V_31 = V_2 -> V_16 != V_2 -> V_10 ;
while ( ! V_26 && ! V_31 ) {
F_10 ( & V_2 -> V_32 , & V_30 , V_33 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_11 () ;
F_12 ( & V_2 -> V_32 , & V_30 ) ;
if ( F_13 ( V_34 ) )
return - V_35 ;
F_3 ( & V_2 -> V_15 ) ;
V_26 = V_2 -> V_26 ;
V_31 = V_2 -> V_16 != V_2 -> V_10 ;
}
F_6 ( & V_2 -> V_15 ) ;
if ( V_26 )
V_11 = F_7 ( V_2 , V_3 , V_11 , V_5 ) ;
else if ( V_31 )
V_11 = F_1 ( V_2 , V_3 , V_11 , V_5 ) ;
return V_11 ;
}
static long
F_14 ( struct V_27 * V_28 , const char T_1 * V_36 , long V_11 ,
T_2 * V_5 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
T_4 V_37 ;
T_3 * V_3 ;
if ( V_11 < sizeof( struct V_8 ) ||
V_38 < V_11 )
return - V_39 ;
V_3 = F_15 ( V_36 , V_11 ) ;
if ( F_16 ( V_3 ) )
return F_17 ( V_3 ) ;
V_37 = F_4 ( ( (struct V_8 * ) V_3 ) -> V_37 ) ;
if ( V_37 > V_40 ) {
V_11 = - V_39 ;
goto V_41;
}
if ( F_18 ( V_2 -> V_42 , V_3 , V_11 ) < 0 )
V_11 = - V_43 ;
V_41:
F_19 ( V_3 ) ;
return V_11 ;
}
static unsigned int
F_20 ( struct V_27 * V_28 , struct V_44 * V_44 , T_5 * V_30 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
unsigned int V_45 ;
F_21 ( V_44 , & V_2 -> V_32 , V_30 ) ;
F_3 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_26 || V_2 -> V_10 != V_2 -> V_16 )
V_45 = V_46 | V_47 ;
else
V_45 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
return V_45 | V_48 ;
}
static int
F_22 ( struct V_1 * V_2 , void T_1 * V_49 )
{
struct V_50 * V_51 = F_23 ( V_2 -> V_42 ) ;
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . type = V_54 ;
V_53 . V_55 = V_51 -> V_55 -> V_56 ;
* ( V_17 * ) & V_53 . V_57 [ 0 ] = F_24 ( V_51 -> V_58 [ 3 ] ) ;
* ( V_17 * ) & V_53 . V_57 [ 4 ] = F_24 ( V_51 -> V_58 [ 4 ] ) ;
F_25 ( V_53 . V_59 , F_26 ( & V_51 -> V_60 ) ,
sizeof( V_53 . V_59 ) ) ;
if ( F_2 ( V_49 , & V_53 , sizeof( V_53 ) ) )
return - V_14 ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
int V_61 ;
F_3 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_25 == 0 ) {
V_2 -> V_25 = - 1 ;
V_61 = 0 ;
} else {
V_61 = - V_62 ;
}
F_6 ( & V_2 -> V_15 ) ;
return V_61 ;
}
static int
F_28 ( struct V_1 * V_2 )
{
int V_61 ;
F_3 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_25 == - 1 ) {
V_2 -> V_25 = 0 ;
V_61 = 0 ;
} else {
V_61 = - V_63 ;
}
F_6 ( & V_2 -> V_15 ) ;
return V_61 ;
}
static int
F_29 ( struct V_27 * V_28 , struct V_44 * V_44 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
F_3 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_25 == - 1 )
V_2 -> V_25 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int
F_30 ( struct V_27 * V_28 , struct V_44 * V_44 ,
unsigned int V_64 , unsigned long V_49 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
switch ( V_64 ) {
case V_65 :
return F_22 ( V_2 , ( void T_1 * ) V_49 ) ;
case V_66 :
return F_27 ( V_2 ) ;
case V_67 :
return F_28 ( V_2 ) ;
default:
return - V_68 ;
}
}
static int
F_31 ( struct V_27 * V_28 , struct V_44 * V_44 ,
unsigned int V_64 , unsigned long V_49 )
{
return F_30 ( V_28 , V_44 , V_64 ,
( unsigned long ) F_32 ( V_49 ) ) ;
}
int F_33 ( struct V_1 * V_2 )
{
static const struct V_69 V_70 = {
. V_71 = F_8 ,
. V_72 = F_14 ,
. V_73 = F_29 ,
. V_74 = F_20 ,
. V_75 = F_30 ,
. V_76 = F_31 ,
} ;
struct V_27 * V_28 ;
int V_61 ;
V_61 = F_34 ( V_2 -> V_55 , L_1 , 0 , & V_28 ) ;
if ( V_61 < 0 )
goto V_41;
strcpy ( V_28 -> V_77 , L_1 ) ;
V_28 -> V_78 = V_79 ;
V_28 -> V_70 = V_70 ;
V_28 -> V_29 = V_2 ;
V_28 -> V_80 = true ;
V_41:
return V_61 ;
}
