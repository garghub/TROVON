static int F_1 ( int V_1 , void * V_2 , int V_3 )
{
int V_4 = V_3 ;
while ( V_3 ) {
int V_5 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_5 <= 0 )
return - 1 ;
if ( V_6 ) {
int V_7 = F_3 ( V_8 , V_2 , V_5 ) ;
if ( V_7 <= 0 || V_7 != V_5 ) {
F_4 ( L_1 ) ;
return - 1 ;
}
}
V_3 -= V_5 ;
V_2 += V_5 ;
}
return V_4 ;
}
static int F_5 ( void * V_9 , int V_3 )
{
int V_10 ;
V_10 = F_1 ( V_11 , V_9 , V_3 ) ;
if ( V_10 <= 0 ) {
F_4 ( L_2 ,
V_3 , V_10 ) ;
return - 1 ;
}
V_12 += V_10 ;
return V_10 ;
}
static void F_6 ( int V_3 )
{
char V_2 [ V_13 ] ;
int V_10 ;
while ( V_3 ) {
V_10 = V_3 > V_13 ? V_13 : V_3 ;
F_5 ( V_2 , V_10 ) ;
V_3 -= V_10 ;
} ;
}
static unsigned int F_7 ( struct V_14 * V_14 )
{
unsigned int V_9 ;
if ( F_5 ( & V_9 , 4 ) < 0 )
return 0 ;
return F_8 ( V_14 , V_9 ) ;
}
static unsigned long long F_9 ( struct V_14 * V_14 )
{
unsigned long long V_9 ;
if ( F_5 ( & V_9 , 8 ) < 0 )
return 0 ;
return F_10 ( V_14 , V_9 ) ;
}
static char * F_11 ( void )
{
char V_2 [ V_13 ] ;
char * V_15 = NULL ;
int V_3 = 0 ;
T_1 V_10 ;
char V_16 ;
for (; ; ) {
V_10 = F_2 ( V_11 , & V_16 , 1 ) ;
if ( V_10 < 0 ) {
F_4 ( L_3 ) ;
goto V_17;
}
if ( ! V_10 ) {
F_4 ( L_4 ) ;
goto V_17;
}
if ( V_6 ) {
int V_7 = F_3 ( V_8 , & V_16 , 1 ) ;
if ( V_7 <= 0 || V_7 != V_10 ) {
F_4 ( L_5 ) ;
goto V_17;
}
}
V_2 [ V_3 ++ ] = V_16 ;
if ( ! V_16 )
break;
}
V_12 += V_3 ;
V_15 = malloc ( V_3 ) ;
if ( V_15 )
memcpy ( V_15 , V_2 , V_3 ) ;
V_17:
return V_15 ;
}
static int F_12 ( struct V_14 * V_14 )
{
unsigned int V_3 ;
V_3 = F_7 ( V_14 ) ;
if ( ! V_3 )
return 0 ;
F_13 ( V_11 , V_3 , V_18 ) ;
V_12 += V_3 ;
return 0 ;
}
static int F_14 ( struct V_14 * V_14 )
{
unsigned int V_3 ;
char * V_2 ;
V_3 = F_7 ( V_14 ) ;
if ( ! V_3 )
return 0 ;
V_2 = malloc ( V_3 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( F_5 ( V_2 , V_3 ) < 0 ) {
free ( V_2 ) ;
return - 1 ;
}
F_15 ( V_14 , V_2 , V_3 ) ;
free ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_14 )
{
unsigned long long V_3 ;
char * V_19 ;
char V_2 [ V_13 ] ;
int V_5 = 0 ;
if ( F_5 ( V_2 , 12 ) < 0 )
return - 1 ;
if ( memcmp ( V_2 , L_6 , 12 ) != 0 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
V_3 = F_9 ( V_14 ) ;
V_19 = malloc ( V_3 ) ;
if ( V_19 == NULL )
return - 1 ;
if ( F_5 ( V_19 , V_3 ) < 0 ) {
F_4 ( L_7 ) ;
free ( V_19 ) ;
return - 1 ;
}
if ( ! F_17 ( V_14 , V_19 , V_3 ,
F_18 ( V_14 ) ) ) {
F_19 ( V_14 , V_14 -> V_20 ) ;
}
free ( V_19 ) ;
if ( F_5 ( V_2 , 13 ) < 0 )
return - 1 ;
if ( memcmp ( V_2 , L_8 , 13 ) != 0 ) {
F_4 ( L_9 ) ;
return - 1 ;
}
V_3 = F_9 ( V_14 ) ;
F_6 ( V_3 ) ;
return V_5 ;
}
static int F_20 ( struct V_14 * V_14 , unsigned long long V_3 )
{
char * V_2 ;
V_2 = malloc ( V_3 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( F_5 ( V_2 , V_3 ) < 0 ) {
free ( V_2 ) ;
return - 1 ;
}
F_21 ( V_14 , V_2 , V_3 ) ;
free ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_14 , char * V_21 ,
unsigned long long V_3 )
{
char * V_2 ;
V_2 = malloc ( V_3 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( F_5 ( V_2 , V_3 ) < 0 ) {
free ( V_2 ) ;
return - 1 ;
}
F_23 ( V_14 , V_2 , V_3 , V_21 ) ;
free ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_14 )
{
unsigned long long V_3 ;
int V_22 ;
int V_23 ;
int V_5 ;
V_22 = F_7 ( V_14 ) ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_3 = F_9 ( V_14 ) ;
V_5 = F_20 ( V_14 , V_3 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_25 ( struct V_14 * V_14 )
{
unsigned long long V_3 ;
char * V_21 ;
int V_24 ;
int V_22 ;
int V_23 , V_25 ;
int V_5 ;
V_24 = F_7 ( V_14 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_21 = F_11 () ;
if ( V_21 == NULL )
return - 1 ;
V_22 = F_7 ( V_14 ) ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
V_3 = F_9 ( V_14 ) ;
V_5 = F_22 ( V_14 , V_21 , V_3 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
T_2 F_26 ( int V_1 , struct V_26 * V_27 , bool V_28 )
{
char V_2 [ V_13 ] ;
char V_29 [] = { 23 , 8 , 68 } ;
char * V_30 ;
int V_31 = 0 ;
int V_32 = 0 ;
int V_33 = 0 ;
T_2 V_3 = - 1 ;
int V_34 ;
int V_35 ;
int V_36 ;
int V_37 ;
struct V_14 * V_14 = NULL ;
int V_38 ;
V_6 = V_28 ;
V_11 = V_1 ;
if ( F_5 ( V_2 , 3 ) < 0 )
return - 1 ;
if ( memcmp ( V_2 , V_29 , 3 ) != 0 ) {
F_4 ( L_10 ) ;
return - 1 ;
}
if ( F_5 ( V_2 , 7 ) < 0 )
return - 1 ;
if ( memcmp ( V_2 , L_11 , 7 ) != 0 ) {
F_4 ( L_12 ) ;
return - 1 ;
}
V_30 = F_11 () ;
if ( V_30 == NULL )
return - 1 ;
if ( V_31 )
printf ( L_13 , V_30 ) ;
free ( V_30 ) ;
if ( F_5 ( V_2 , 1 ) < 0 )
return - 1 ;
V_34 = V_2 [ 0 ] ;
V_35 = F_27 () ;
if ( F_28 ( V_27 ) ) {
F_4 ( L_14 ) ;
goto V_17;
}
V_14 = V_27 -> V_14 ;
F_29 ( V_14 , V_39 ) ;
F_30 ( V_14 , V_34 ) ;
F_31 ( V_14 , V_35 ) ;
if ( F_5 ( V_2 , 1 ) < 0 )
goto V_17;
V_36 = V_2 [ 0 ] ;
V_37 = F_7 ( V_14 ) ;
if ( ! V_37 )
goto V_17;
F_19 ( V_14 , V_36 ) ;
F_32 ( V_14 , V_37 ) ;
V_38 = F_16 ( V_14 ) ;
if ( V_38 )
goto V_17;
V_38 = F_24 ( V_14 ) ;
if ( V_38 )
goto V_17;
V_38 = F_25 ( V_14 ) ;
if ( V_38 )
goto V_17;
V_38 = F_12 ( V_14 ) ;
if ( V_38 )
goto V_17;
V_38 = F_14 ( V_14 ) ;
if ( V_38 )
goto V_17;
V_3 = V_12 ;
V_6 = false ;
if ( V_32 ) {
F_33 ( V_14 ) ;
} else if ( V_33 ) {
F_34 ( V_14 ) ;
}
V_14 = NULL ;
V_17:
if ( V_14 )
F_35 ( V_27 ) ;
return V_3 ;
}
