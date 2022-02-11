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
type == F_17 ( V_19 . V_29 ) ||
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
int F_24 ( void )
{
return F_25 ( & V_36 , & V_37 ) ;
}
static inline void F_26 ( enum V_38 V_39 )
{
F_27 ( F_28 ( V_38 ) != V_40 ) ;
F_29 ( V_38 , V_39 ) ;
}
static void F_30 ( enum V_38 V_39 )
{
F_27 ( F_28 ( V_38 ) != V_39 ) ;
F_29 ( V_38 , V_40 ) ;
}
void F_31 ( void )
{
F_26 ( V_41 ) ;
}
void F_32 ( void )
{
F_30 ( V_41 ) ;
}
void F_33 ( struct V_42 * V_43 )
{
F_27 ( F_34 () ) ;
if ( F_28 ( V_38 ) == V_41 ) {
F_35 () ;
F_36 ( F_37 ( V_43 ) , V_44 ) ;
}
F_26 ( V_45 ) ;
}
void F_38 ( struct V_42 * V_46 )
{
F_27 ( F_34 () ) ;
F_30 ( V_45 ) ;
if ( F_39 ( F_37 ( V_46 ) , V_44 ) )
F_40 () ;
}
enum V_38 F_41 ( void )
{
if ( F_42 () )
return V_40 ;
return F_28 ( V_38 ) ;
}
void F_43 ( void )
{
F_44 () ;
if ( F_41 () == V_41 ) {
F_35 () ;
F_40 () ;
}
F_45 () ;
}
