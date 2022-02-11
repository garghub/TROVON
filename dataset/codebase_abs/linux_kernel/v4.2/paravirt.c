void F_1 ( void )
{
}
T_1 F_2 ( T_1 V_1 )
{
return V_1 ;
}
T_2 F_3 ( T_2 V_1 )
{
return V_1 ;
}
void T_3 F_4 ( void )
{
F_5 ( V_2 L_1 ,
V_3 . V_4 ) ;
}
unsigned F_6 ( void )
{
return 0 ;
}
unsigned F_7 ( unsigned V_5 )
{
return V_5 ;
}
unsigned F_8 ( void * V_6 ,
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
F_9 ( sizeof( * V_12 ) != 5 ) ;
return 5 ;
}
unsigned F_10 ( void * V_6 , const void * V_7 ,
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
static void * F_11 ( T_5 type )
{
struct V_15 V_16 = {
. V_17 = V_17 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_22 = V_22 ,
#ifdef F_12
. V_23 = V_23 ,
#endif
} ;
return * ( ( void * * ) & V_16 + type ) ;
}
unsigned F_13 ( T_5 type , T_4 V_24 , void * V_6 ,
unsigned long V_9 , unsigned V_5 )
{
void * V_25 = F_11 ( type ) ;
unsigned V_26 ;
if ( V_25 == NULL )
V_26 = F_14 ( V_6 , V_5 , V_27 , V_27 + sizeof( V_27 ) ) ;
else if ( V_25 == F_1 )
V_26 = F_6 () ;
else if ( V_25 == F_2 )
V_26 = F_15 ( V_6 , V_5 ) ;
else if ( V_25 == F_3 )
V_26 = F_16 ( V_6 , V_5 ) ;
else if ( type == F_17 ( V_19 . V_28 ) ||
#ifdef F_18
type == F_17 ( V_19 . V_29 ) ||
#endif
type == F_17 ( V_19 . V_30 ) ||
type == F_17 ( V_19 . V_31 ) )
V_26 = F_10 ( V_6 , V_25 , V_9 , V_5 ) ;
else
V_26 = F_8 ( V_6 , V_25 , V_32 ,
V_9 , V_24 , V_5 ) ;
return V_26 ;
}
unsigned F_14 ( void * V_6 , unsigned V_5 ,
const char * V_33 , const char * V_34 )
{
unsigned V_35 = V_34 - V_33 ;
if ( V_35 > V_5 || V_33 == NULL )
V_35 = V_5 ;
else
memcpy ( V_6 , V_33 , V_35 ) ;
return V_35 ;
}
static void F_19 ( void )
{
F_20 () ;
}
static void F_21 ( void )
{
F_22 () ;
}
static void F_23 ( unsigned long V_9 )
{
F_24 ( V_9 ) ;
}
static T_2 F_25 ( int V_36 )
{
return 0 ;
}
int F_26 ( void )
{
return F_27 ( & V_37 , & V_38 ) ;
}
static inline void F_28 ( enum V_39 V_40 )
{
F_29 ( F_30 ( V_39 ) != V_41 ) ;
F_31 ( V_39 , V_40 ) ;
}
static void F_32 ( enum V_39 V_40 )
{
F_29 ( F_30 ( V_39 ) != V_40 ) ;
F_31 ( V_39 , V_41 ) ;
}
void F_33 ( void )
{
F_28 ( V_42 ) ;
}
void F_34 ( void )
{
F_32 ( V_42 ) ;
}
void F_35 ( void )
{
F_36 () ;
if ( F_37 () == V_42 ) {
F_38 () ;
F_39 () ;
}
F_40 () ;
}
void F_41 ( struct V_43 * V_44 )
{
F_29 ( F_42 () ) ;
if ( F_30 ( V_39 ) == V_42 ) {
F_38 () ;
F_43 ( F_44 ( V_44 ) , V_45 ) ;
}
F_28 ( V_46 ) ;
}
void F_45 ( struct V_43 * V_47 )
{
F_29 ( F_42 () ) ;
F_32 ( V_46 ) ;
if ( F_46 ( F_44 ( V_47 ) , V_45 ) )
F_39 () ;
}
enum V_39 F_37 ( void )
{
if ( F_47 () )
return V_41 ;
return F_30 ( V_39 ) ;
}
