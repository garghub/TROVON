static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = V_3 -> signal -> V_1 ;
F_2 ( V_2 == F_3 ( - V_4 ) ) ;
return V_2 ;
}
static struct V_1 * F_4 ( void )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
goto V_6;
V_2 -> V_7 = F_5 ( V_8 , V_5 ) ;
if ( ! V_2 -> V_7 )
goto V_9;
F_6 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = F_7 ( 0 , 0 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
return V_2 ;
V_9:
F_8 ( V_2 ) ;
V_6:
return NULL ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_13 != 0 ) ;
F_8 ( V_2 -> V_7 ) ;
F_8 ( V_2 ) ;
}
static void F_10 ( const char * V_14 , T_1 V_11 ,
unsigned char * V_7 , T_2 V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = V_3 ;
T_3 V_20 = F_11 ( V_19 ) ;
T_4 V_21 = F_12 ( & V_22 , F_13 ( V_19 ) ) ;
T_4 V_23 = F_12 ( & V_22 , F_14 ( V_19 ) ) ;
unsigned int V_24 = F_15 ( V_19 ) ;
V_17 = F_16 ( NULL , V_5 , V_25 ) ;
if ( V_17 ) {
char V_26 [ sizeof( V_19 -> V_27 ) ] ;
F_17 ( V_17 , L_1
L_2 , V_14 , V_20 , V_21 ,
V_23 , V_24 , F_18 ( V_11 ) , F_19 ( V_11 ) ) ;
F_20 ( V_26 , V_19 ) ;
F_21 ( V_17 , V_26 ) ;
F_17 ( V_17 , L_3 ) ;
F_22 ( V_17 , V_7 , V_15 ) ;
F_23 ( V_17 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == 0 )
return;
if ( V_28 == 0 ) {
V_2 -> V_13 = 0 ;
return;
}
F_10 ( L_4 , V_2 -> V_11 , V_2 -> V_7 , V_2 -> V_13 ) ;
V_2 -> V_13 = 0 ;
}
void F_25 ( void )
{
struct V_1 * V_2 ;
V_2 = F_26 ( & V_3 -> signal -> V_1 , F_3 ( - V_4 ) ) ;
if ( ! V_2 )
return;
F_24 ( V_2 ) ;
F_9 ( V_2 ) ;
}
void F_27 ( struct V_29 * V_30 )
{
V_30 -> V_31 = V_3 -> signal -> V_31 ;
}
void F_28 ( struct V_32 * V_33 , char V_34 )
{
T_1 V_11 ;
V_11 = F_7 ( V_33 -> V_35 -> V_36 , V_33 -> V_35 -> V_37 ) + V_33 -> V_38 ;
if ( F_29 () )
return;
if ( V_28 )
F_10 ( L_5 , V_11 , & V_34 , 1 ) ;
}
int F_29 ( void )
{
struct V_1 * V_2 ;
if ( ~ V_3 -> signal -> V_31 & V_39 )
return - V_40 ;
V_2 = F_1 () ;
if ( ! F_30 ( V_2 ) ) {
F_31 ( & V_2 -> V_10 ) ;
F_24 ( V_2 ) ;
F_32 ( & V_2 -> V_10 ) ;
}
return 0 ;
}
static struct V_1 * F_33 ( void )
{
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( V_2 )
return V_2 ;
V_2 = F_4 () ;
if ( V_2 == NULL ) {
F_34 ( L_6 ) ;
return NULL ;
}
if ( F_35 ( & V_3 -> signal -> V_1 , NULL , V_2 ) != NULL )
F_9 ( V_2 ) ;
return F_1 () ;
}
void F_36 ( struct V_32 * V_33 , const void * V_7 , T_2 V_15 )
{
struct V_1 * V_2 ;
unsigned int V_12 = ! ! F_37 ( V_33 ) ;
unsigned int V_31 ;
T_1 V_11 ;
V_31 = F_38 ( V_3 -> signal -> V_31 ) ;
if ( ~ V_31 & V_39 )
return;
if ( F_39 ( V_15 == 0 ) )
return;
if ( V_33 -> V_35 -> type == V_41
&& V_33 -> V_35 -> V_42 == V_43 )
return;
if ( ( ~ V_31 & V_44 ) && V_12 && ! F_40 ( V_33 ) )
return;
V_2 = F_33 () ;
if ( F_30 ( V_2 ) )
return;
F_31 ( & V_2 -> V_10 ) ;
V_11 = F_7 ( V_33 -> V_35 -> V_36 , V_33 -> V_35 -> V_37 ) + V_33 -> V_38 ;
if ( V_2 -> V_11 != V_11 || V_2 -> V_12 != V_12 ) {
F_24 ( V_2 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_12 = V_12 ;
}
do {
T_2 V_45 ;
V_45 = V_8 - V_2 -> V_13 ;
if ( V_45 > V_15 )
V_45 = V_15 ;
memcpy ( V_2 -> V_7 + V_2 -> V_13 , V_7 , V_45 ) ;
V_2 -> V_13 += V_45 ;
V_7 += V_45 ;
V_15 -= V_45 ;
if ( V_2 -> V_13 == V_8 )
F_24 ( V_2 ) ;
} while ( V_15 != 0 );
F_32 ( & V_2 -> V_10 ) ;
}
