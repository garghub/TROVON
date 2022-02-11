static struct V_1 * F_1 ( const char * V_2 )
{
int V_3 = 0 ;
while ( V_4 [ V_3 ] ) {
if ( F_2 ( V_2 , V_4 [ V_3 ] -> V_5 ) )
break;
V_3 ++ ;
}
return V_4 [ V_3 ] ;
}
static void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( V_9 -> V_10 )
V_7 -> V_11 -> V_12 ( V_9 -> V_10 ) ;
F_4 ( ( unsigned long ) V_9 -> V_13 , 1 ) ;
F_5 ( V_9 ) ;
}
static struct V_8 * F_6 ( struct V_6 * V_7 , T_1 V_14 )
{
struct V_8 * V_9 = F_7 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_10 = V_7 -> V_11 -> V_15 ( V_14 ) ;
V_9 -> V_13 = ( void * ) F_8 ( V_14 | V_16 , 1 ) ;
if ( ! V_9 -> V_10 || ! V_9 -> V_13 ) {
F_3 ( V_7 , V_9 ) ;
V_9 = NULL ;
}
return V_9 ;
}
T_2 F_9 ( const char * V_7 , char * V_17 )
{
T_2 V_18 = 0 ;
int V_3 = 0 ;
while ( V_4 [ V_3 ] ) {
if ( ! strcmp ( V_7 , V_4 [ V_3 ] -> V_5 ) )
V_18 += F_10 ( V_17 + V_18 , V_19 - V_18 - 2 ,
L_1 , V_4 [ V_3 ] -> V_5 ) ;
else
V_18 += F_10 ( V_17 + V_18 , V_19 - V_18 - 2 ,
L_2 , V_4 [ V_3 ] -> V_5 ) ;
V_3 ++ ;
}
V_18 += F_10 ( V_17 + V_18 , V_19 - V_18 , L_3 ) ;
return V_18 ;
}
bool F_11 ( const char * V_7 )
{
return F_1 ( V_7 ) != NULL ;
}
struct V_8 * F_12 ( struct V_6 * V_7 )
{
return * F_13 ( V_7 -> V_20 ) ;
}
void F_14 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
F_15 ( V_7 -> V_20 ) ;
}
int F_16 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const unsigned char * V_21 , T_3 * V_22 )
{
return V_7 -> V_11 -> V_2 ( V_21 , V_9 -> V_13 , V_22 ,
V_9 -> V_10 ) ;
}
int F_17 ( struct V_6 * V_7 , const unsigned char * V_21 ,
T_3 V_23 , unsigned char * V_24 )
{
return V_7 -> V_11 -> V_25 ( V_21 , V_23 , V_24 ) ;
}
static int F_18 ( struct V_6 * V_7 ,
unsigned long V_26 , unsigned long V_27 )
{
struct V_8 * V_9 ;
switch ( V_26 ) {
case V_28 :
if ( F_19 ( * F_20 ( V_7 -> V_20 , V_27 ) ) )
break;
V_9 = F_6 ( V_7 , V_29 ) ;
if ( F_21 ( V_9 ) ) {
F_22 ( L_4 ) ;
return V_30 ;
}
* F_20 ( V_7 -> V_20 , V_27 ) = V_9 ;
break;
case V_31 :
case V_32 :
V_9 = * F_20 ( V_7 -> V_20 , V_27 ) ;
if ( ! F_21 ( V_9 ) )
F_3 ( V_7 , V_9 ) ;
* F_20 ( V_7 -> V_20 , V_27 ) = NULL ;
break;
default:
break;
}
return V_33 ;
}
static int F_23 ( struct V_34 * V_35 ,
unsigned long V_26 , void * V_36 )
{
unsigned long V_27 = ( unsigned long ) V_36 ;
struct V_6 * V_7 = F_24 ( V_35 , F_25 ( * V_7 ) , V_37 ) ;
return F_18 ( V_7 , V_26 , V_27 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
unsigned long V_27 ;
int V_38 ;
V_7 -> V_37 . V_39 = F_23 ;
V_7 -> V_20 = F_27 ( struct V_8 * ) ;
if ( ! V_7 -> V_20 )
return - V_40 ;
F_28 () ;
F_29 (cpu) {
V_38 = F_18 ( V_7 , V_28 , V_27 ) ;
if ( V_38 == V_30 )
goto V_41;
}
F_30 ( & V_7 -> V_37 ) ;
F_31 () ;
return 0 ;
V_41:
F_29 (cpu)
F_18 ( V_7 , V_32 , V_27 ) ;
F_31 () ;
return - V_40 ;
}
void F_32 ( struct V_6 * V_7 )
{
unsigned long V_27 ;
F_28 () ;
F_29 (cpu)
F_18 ( V_7 , V_32 , V_27 ) ;
F_33 ( & V_7 -> V_37 ) ;
F_31 () ;
F_34 ( V_7 -> V_20 ) ;
F_5 ( V_7 ) ;
}
struct V_6 * F_35 ( const char * V_2 )
{
struct V_6 * V_7 ;
struct V_1 * V_11 ;
int error ;
V_11 = F_1 ( V_2 ) ;
if ( ! V_11 )
return F_36 ( - V_42 ) ;
V_7 = F_37 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return F_36 ( - V_40 ) ;
V_7 -> V_11 = V_11 ;
error = F_26 ( V_7 ) ;
if ( error ) {
F_5 ( V_7 ) ;
return F_36 ( error ) ;
}
return V_7 ;
}
