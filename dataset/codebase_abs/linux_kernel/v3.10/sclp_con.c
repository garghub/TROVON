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
static void
F_16 ( struct V_17 * V_17 , const char * V_18 ,
unsigned int V_19 )
{
unsigned long V_4 ;
void * V_5 ;
int V_20 ;
if ( V_19 == 0 )
return;
F_3 ( & V_6 , V_4 ) ;
do {
if ( V_13 == NULL ) {
while ( F_6 ( & V_9 ) ) {
if ( V_11 )
goto V_21;
F_8 ( & V_6 , V_4 ) ;
F_14 () ;
F_3 ( & V_6 , V_4 ) ;
}
V_5 = V_9 . V_22 ;
F_4 ( (struct V_8 * ) V_5 ) ;
V_13 = F_17 ( V_5 , V_23 ,
V_24 ) ;
}
V_20 = F_18 ( V_13 , ( const unsigned char * )
V_18 , V_19 ) ;
if ( V_20 == V_19 )
break;
F_8 ( & V_6 , V_4 ) ;
F_10 () ;
F_3 ( & V_6 , V_4 ) ;
V_18 += V_20 ;
V_19 -= V_20 ;
} while ( V_19 > 0 );
if ( V_13 != NULL && F_19 ( V_13 ) != 0 &&
! F_12 ( & V_15 ) ) {
F_20 ( & V_15 ) ;
V_15 . V_25 = F_15 ;
V_15 . V_16 = 0UL ;
V_15 . V_26 = V_27 + V_28 / 10 ;
F_21 ( & V_15 ) ;
}
V_21:
F_8 ( & V_6 , V_4 ) ;
}
static struct V_29 *
F_22 ( struct V_17 * V_30 , int * V_31 )
{
* V_31 = V_30 -> V_31 ;
return V_32 ;
}
static void
F_23 ( void )
{
F_10 () ;
F_11 () ;
}
static void F_24 ( void )
{
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
V_11 = 0 ;
F_8 ( & V_6 , V_4 ) ;
F_10 () ;
}
static void F_25 ( void )
{
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
V_11 = 1 ;
F_8 ( & V_6 , V_4 ) ;
F_23 () ;
}
static int F_26 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_16 )
{
F_23 () ;
return V_36 ;
}
void F_27 ( enum V_37 V_37 )
{
switch ( V_37 ) {
case V_38 :
F_25 () ;
break;
case V_39 :
case V_40 :
F_24 () ;
break;
}
}
static int T_1
F_28 ( void )
{
void * V_5 ;
int V_41 ;
int V_3 ;
if ( ! V_42 )
return 0 ;
V_3 = F_29 () ;
if ( V_3 )
return V_3 ;
F_30 ( & V_9 ) ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_5 = ( void * ) F_31 ( V_44 | V_45 ) ;
F_5 ( V_5 , & V_9 ) ;
}
F_30 ( & V_10 ) ;
F_32 ( & V_6 ) ;
V_13 = NULL ;
F_20 ( & V_15 ) ;
if ( V_46 )
V_23 = 76 ;
else
V_23 = 80 ;
V_24 = 8 ;
F_33 ( & V_47 , & V_48 ) ;
F_34 ( & V_49 ) ;
F_35 ( & V_50 ) ;
return 0 ;
}
