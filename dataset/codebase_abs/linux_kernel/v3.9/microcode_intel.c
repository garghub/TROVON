static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & F_2 ( V_1 ) ;
unsigned int V_6 [ 2 ] ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_7 = F_3 ( 0x00000001 ) ;
if ( ( V_5 -> V_8 >= 5 ) || ( V_5 -> V_9 > 6 ) ) {
F_4 ( V_10 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
V_3 -> V_11 = 1 << ( ( V_6 [ 1 ] >> 18 ) & 7 ) ;
}
V_3 -> V_12 = V_5 -> V_13 ;
F_5 ( L_1 ,
V_1 , V_3 -> V_7 , V_3 -> V_11 , V_3 -> V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 , int V_16 )
{
struct V_2 V_17 ;
unsigned int V_3 , V_18 , V_19 ;
F_1 ( V_16 , & V_17 ) ;
V_3 = V_17 . V_7 ;
V_18 = V_17 . V_11 ;
V_19 = V_17 . V_12 ;
return F_7 ( V_3 , V_18 , V_15 , V_19 ) ;
}
int F_8 ( int V_16 )
{
struct V_14 * V_15 ;
struct V_20 * V_21 ;
unsigned int V_6 [ 2 ] ;
int V_1 = F_9 () ;
struct V_4 * V_5 = & F_2 ( V_1 ) ;
V_21 = V_20 + V_16 ;
V_15 = V_21 -> V_22 ;
F_10 ( V_1 != V_16 ) ;
if ( V_15 == NULL )
return 0 ;
if ( F_6 ( V_15 , V_16 ) == 0 )
return 0 ;
F_11 ( V_23 ,
( unsigned long ) V_15 -> V_24 ,
( unsigned long ) V_15 -> V_24 >> 16 >> 16 ) ;
F_11 ( V_25 , 0 , 0 ) ;
F_12 () ;
F_4 ( V_25 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
if ( V_6 [ 1 ] != V_15 -> V_26 . V_12 ) {
F_13 ( L_2 ,
V_1 , V_15 -> V_26 . V_12 ) ;
return - 1 ;
}
F_5 ( L_3 ,
V_1 , V_6 [ 1 ] ,
V_15 -> V_26 . V_27 & 0xffff ,
V_15 -> V_26 . V_27 >> 24 ,
( V_15 -> V_26 . V_27 >> 16 ) & 0xff ) ;
V_21 -> V_17 . V_12 = V_6 [ 1 ] ;
V_5 -> V_13 = V_6 [ 1 ] ;
return 0 ;
}
static enum V_28 F_14 ( int V_16 , void * V_29 , T_1 V_30 ,
int (* F_15)( void * , const void * , T_1 ) )
{
struct V_20 * V_21 = V_20 + V_16 ;
T_2 * V_31 = V_29 , * V_32 = NULL , * V_22 = NULL ;
int V_33 = V_21 -> V_17 . V_12 ;
unsigned int V_34 = V_30 ;
enum V_28 V_35 = V_36 ;
unsigned int V_37 = 0 ;
unsigned int V_3 , V_18 ;
while ( V_34 ) {
struct V_38 V_39 ;
unsigned int V_40 ;
if ( F_15 ( & V_39 , V_31 , sizeof( V_39 ) ) )
break;
V_40 = F_16 ( & V_39 ) ;
if ( ! V_40 || V_40 > V_34 ) {
F_13 ( L_4 ) ;
break;
}
if ( ! V_22 || V_40 > V_37 ) {
F_17 ( V_22 ) ;
V_22 = F_18 ( V_40 ) ;
if ( ! V_22 )
break;
V_37 = V_40 ;
}
if ( F_15 ( V_22 , V_31 , V_40 ) ||
F_19 ( V_22 , 1 ) < 0 ) {
break;
}
V_3 = V_21 -> V_17 . V_7 ;
V_18 = V_21 -> V_17 . V_11 ;
if ( F_7 ( V_3 , V_18 , V_22 , V_33 ) ) {
F_17 ( V_32 ) ;
V_33 = V_39 . V_12 ;
V_32 = V_22 ;
V_22 = NULL ;
}
V_31 += V_40 ;
V_34 -= V_40 ;
}
F_17 ( V_22 ) ;
if ( V_34 ) {
F_17 ( V_32 ) ;
V_35 = V_41 ;
goto V_42;
}
if ( ! V_32 ) {
V_35 = V_43 ;
goto V_42;
}
F_17 ( V_21 -> V_22 ) ;
V_21 -> V_22 = (struct V_14 * ) V_32 ;
F_20 ( V_32 ) ;
F_21 ( L_5 ,
V_16 , V_33 , V_21 -> V_17 . V_12 ) ;
V_42:
return V_35 ;
}
static int F_22 ( void * V_44 , const void * V_45 , T_1 V_46 )
{
memcpy ( V_44 , V_45 , V_46 ) ;
return 0 ;
}
static enum V_28 F_23 ( int V_16 , struct V_47 * V_47 ,
bool V_48 )
{
char V_49 [ 30 ] ;
struct V_4 * V_5 = & F_2 ( V_16 ) ;
const struct V_50 * V_50 ;
enum V_28 V_51 ;
sprintf ( V_49 , L_6 ,
V_5 -> V_9 , V_5 -> V_8 , V_5 -> V_52 ) ;
if ( F_24 ( & V_50 , V_49 , V_47 ) ) {
F_21 ( L_7 , V_49 ) ;
return V_43 ;
}
V_51 = F_14 ( V_16 , ( void * ) V_50 -> V_29 ,
V_50 -> V_30 , & F_22 ) ;
F_25 ( V_50 ) ;
return V_51 ;
}
static int F_26 ( void * V_44 , const void * V_45 , T_1 V_46 )
{
return F_27 ( V_44 , V_45 , V_46 ) ;
}
static enum V_28
F_28 ( int V_16 , const void T_3 * V_53 , T_1 V_30 )
{
return F_14 ( V_16 , ( void * ) V_53 , V_30 , & F_26 ) ;
}
static void F_29 ( int V_16 )
{
struct V_20 * V_21 = V_20 + V_16 ;
F_17 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
}
struct V_54 * T_4 F_30 ( void )
{
struct V_4 * V_5 = & F_2 ( 0 ) ;
if ( V_5 -> V_55 != V_56 || V_5 -> V_9 < 6 ||
F_31 ( V_5 , V_57 ) ) {
F_13 ( L_8 , V_5 -> V_9 ) ;
return NULL ;
}
return & V_58 ;
}
