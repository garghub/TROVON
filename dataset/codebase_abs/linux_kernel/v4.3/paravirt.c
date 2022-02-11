T_1 F_1 ( T_1 V_1 )
{
return V_1 ;
}
T_2 F_2 ( T_2 V_1 )
{
return V_1 ;
}
void T_3 F_3 ( void )
{
F_4 ( V_2 L_1 ,
V_3 . V_4 ) ;
}
unsigned F_5 ( void )
{
return 0 ;
}
unsigned F_6 ( unsigned V_5 )
{
return V_5 ;
}
unsigned F_7 ( void * V_6 ,
const void * V_7 , T_4 V_8 ,
unsigned long V_9 , T_4 V_10 ,
unsigned V_5 )
{
struct V_11 * V_12 = V_6 ;
unsigned long V_13 = ( unsigned long ) V_7 - ( V_9 + 5 ) ;
if ( V_8 & ~ V_10 )
return V_5 ;
if ( V_5 < 5 )
return V_5 ;
V_12 -> V_14 = 0xe8 ;
V_12 -> V_13 = V_13 ;
F_8 ( sizeof( * V_12 ) != 5 ) ;
return 5 ;
}
unsigned F_9 ( void * V_6 , const void * V_7 ,
unsigned long V_9 , unsigned V_5 )
{
struct V_11 * V_12 = V_6 ;
unsigned long V_13 = ( unsigned long ) V_7 - ( V_9 + 5 ) ;
if ( V_5 < 5 )
return V_5 ;
V_12 -> V_14 = 0xe9 ;
V_12 -> V_13 = V_13 ;
return 5 ;
}
static void * F_10 ( T_5 type )
{
struct V_15 V_16 = {
. V_17 = V_17 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_22 = V_22 ,
#ifdef F_11
. V_23 = V_23 ,
#endif
} ;
return * ( ( void * * ) & V_16 + type ) ;
}
unsigned F_12 ( T_5 type , T_4 V_24 , void * V_6 ,
unsigned long V_9 , unsigned V_5 )
{
void * V_25 = F_10 ( type ) ;
unsigned V_26 ;
if ( V_25 == NULL )
V_26 = F_13 ( V_6 , V_5 , V_27 , V_27 + sizeof( V_27 ) ) ;
else if ( V_25 == V_28 )
V_26 = F_5 () ;
else if ( V_25 == F_1 )
V_26 = F_14 ( V_6 , V_5 ) ;
else if ( V_25 == F_2 )
V_26 = F_15 ( V_6 , V_5 ) ;
else if ( type == F_16 ( V_19 . V_29 ) ||
#ifdef F_17
type == F_16 ( V_19 . V_30 ) ||
#endif
type == F_16 ( V_19 . V_31 ) ||
type == F_16 ( V_19 . V_32 ) )
V_26 = F_9 ( V_6 , V_25 , V_9 , V_5 ) ;
else
V_26 = F_7 ( V_6 , V_25 , V_33 ,
V_9 , V_24 , V_5 ) ;
return V_26 ;
}
unsigned F_13 ( void * V_6 , unsigned V_5 ,
const char * V_34 , const char * V_35 )
{
unsigned V_36 = V_35 - V_34 ;
if ( V_36 > V_5 || V_34 == NULL )
V_36 = V_5 ;
else
memcpy ( V_6 , V_34 , V_36 ) ;
return V_36 ;
}
static void F_18 ( void )
{
F_19 () ;
}
static void F_20 ( void )
{
F_21 () ;
}
static void F_22 ( unsigned long V_9 )
{
F_23 ( V_9 ) ;
}
static T_2 F_24 ( int V_37 )
{
return 0 ;
}
int F_25 ( void )
{
return F_26 ( & V_38 , & V_39 ) ;
}
static inline void F_27 ( enum V_40 V_41 )
{
F_28 ( F_29 ( V_40 ) != V_42 ) ;
F_30 ( V_40 , V_41 ) ;
}
static void F_31 ( enum V_40 V_41 )
{
F_28 ( F_29 ( V_40 ) != V_41 ) ;
F_30 ( V_40 , V_42 ) ;
}
void F_32 ( void )
{
F_27 ( V_43 ) ;
}
void F_33 ( void )
{
F_31 ( V_43 ) ;
}
void F_34 ( void )
{
F_35 () ;
if ( F_36 () == V_43 ) {
F_37 () ;
F_38 () ;
}
F_39 () ;
}
void F_40 ( struct V_44 * V_45 )
{
F_28 ( F_41 () ) ;
if ( F_29 ( V_40 ) == V_43 ) {
F_37 () ;
F_42 ( F_43 ( V_45 ) , V_46 ) ;
}
F_27 ( V_47 ) ;
}
void F_44 ( struct V_44 * V_48 )
{
F_28 ( F_41 () ) ;
F_31 ( V_47 ) ;
if ( F_45 ( F_43 ( V_48 ) , V_46 ) )
F_38 () ;
}
enum V_40 F_36 ( void )
{
if ( F_46 () )
return V_42 ;
return F_29 ( V_40 ) ;
}
