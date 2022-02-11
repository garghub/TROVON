static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
void * V_5 ;
do {
V_5 = F_2 ( V_2 ) ;
F_3 ( & V_6 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( (struct V_8 * ) V_5 , & V_9 ) ;
V_2 = NULL ;
if ( ! F_6 ( & V_10 ) )
V_2 = F_7 ( & V_10 ,
struct V_1 , V_7 ) ;
if ( ! V_2 || V_11 ) {
V_12 = 0 ;
F_8 ( & V_6 , V_4 ) ;
break;
}
F_8 ( & V_6 , V_4 ) ;
} while ( F_9 ( V_2 , F_1 ) );
}
static void F_10 ( void )
{
struct V_1 * V_2 ;
unsigned long V_4 ;
int V_3 ;
F_3 ( & V_6 , V_4 ) ;
if ( V_13 )
F_5 ( & V_13 -> V_7 , & V_10 ) ;
V_13 = NULL ;
if ( V_12 || V_11 )
goto V_14;
if ( F_6 ( & V_10 ) )
goto V_14;
V_2 = F_7 ( & V_10 , struct V_1 ,
V_7 ) ;
V_12 = 1 ;
F_8 ( & V_6 , V_4 ) ;
V_3 = F_9 ( V_2 , F_1 ) ;
if ( V_3 )
F_1 ( V_2 , V_3 ) ;
return;
V_14:
F_8 ( & V_6 , V_4 ) ;
}
static void F_11 ( void )
{
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
if ( F_12 ( & V_15 ) )
F_13 ( & V_15 ) ;
while ( V_12 ) {
F_8 ( & V_6 , V_4 ) ;
F_14 () ;
F_3 ( & V_6 , V_4 ) ;
}
F_8 ( & V_6 , V_4 ) ;
}
static void
F_15 ( unsigned long V_16 )
{
F_10 () ;
}
static int
F_16 ( void )
{
struct V_8 * V_7 ;
struct V_1 * V_2 ;
void * V_5 ;
if ( ! V_17 )
return 0 ;
V_7 = V_10 . V_18 ;
if ( V_12 )
V_7 = V_7 -> V_18 ;
if ( V_7 == & V_10 )
return 0 ;
F_4 ( V_7 ) ;
V_2 = F_17 ( V_7 , struct V_1 , V_7 ) ;
V_5 = F_2 ( V_2 ) ;
F_5 ( (struct V_8 * ) V_5 , & V_9 ) ;
return 1 ;
}
static void
F_18 ( struct V_19 * V_19 , const char * V_20 ,
unsigned int V_21 )
{
unsigned long V_4 ;
void * V_5 ;
int V_22 ;
if ( V_21 == 0 )
return;
F_3 ( & V_6 , V_4 ) ;
do {
if ( V_13 == NULL ) {
if ( F_6 ( & V_9 ) )
V_23 ++ ;
while ( F_6 ( & V_9 ) ) {
if ( V_11 )
goto V_24;
if ( F_16 () )
break;
F_8 ( & V_6 , V_4 ) ;
F_14 () ;
F_3 ( & V_6 , V_4 ) ;
}
V_5 = V_9 . V_18 ;
F_4 ( (struct V_8 * ) V_5 ) ;
V_13 = F_19 ( V_5 , V_25 ,
V_26 ) ;
}
V_22 = F_20 ( V_13 , ( const unsigned char * )
V_20 , V_21 ) ;
if ( V_22 == V_21 )
break;
F_8 ( & V_6 , V_4 ) ;
F_10 () ;
F_3 ( & V_6 , V_4 ) ;
V_20 += V_22 ;
V_21 -= V_22 ;
} while ( V_21 > 0 );
if ( V_13 != NULL && F_21 ( V_13 ) != 0 &&
! F_12 ( & V_15 ) ) {
F_22 ( & V_15 ) ;
V_15 . V_27 = F_15 ;
V_15 . V_16 = 0UL ;
V_15 . V_28 = V_29 + V_30 / 10 ;
F_23 ( & V_15 ) ;
}
V_24:
F_8 ( & V_6 , V_4 ) ;
}
static struct V_31 *
F_24 ( struct V_19 * V_32 , int * V_33 )
{
* V_33 = V_32 -> V_33 ;
return V_34 ;
}
static void
F_25 ( void )
{
F_10 () ;
F_11 () ;
}
static void F_26 ( void )
{
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
V_11 = 0 ;
F_8 ( & V_6 , V_4 ) ;
F_10 () ;
}
static void F_27 ( void )
{
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
V_11 = 1 ;
F_8 ( & V_6 , V_4 ) ;
F_25 () ;
}
static int F_28 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_16 )
{
F_25 () ;
return V_38 ;
}
void F_29 ( enum V_39 V_39 )
{
switch ( V_39 ) {
case V_40 :
F_27 () ;
break;
case V_41 :
case V_42 :
F_26 () ;
break;
}
}
static int T_1
F_30 ( void )
{
void * V_5 ;
int V_43 ;
int V_3 ;
if ( ! ( V_44 || V_45 ) )
return 0 ;
V_3 = F_31 () ;
if ( V_3 )
return V_3 ;
F_32 ( & V_9 ) ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_5 = ( void * ) F_33 ( V_47 | V_48 ) ;
F_5 ( V_5 , & V_9 ) ;
}
F_32 ( & V_10 ) ;
F_34 ( & V_6 ) ;
V_13 = NULL ;
F_22 ( & V_15 ) ;
if ( V_49 )
V_25 = 76 ;
else
V_25 = 80 ;
V_26 = 8 ;
F_35 ( & V_50 , & V_51 ) ;
F_36 ( & V_52 ) ;
F_37 ( & V_53 ) ;
return 0 ;
}
