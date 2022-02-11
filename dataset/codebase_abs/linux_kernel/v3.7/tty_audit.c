static struct V_1 * F_1 ( int V_2 , int V_3 ,
int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
goto V_7;
V_5 -> V_8 = F_2 ( V_9 , V_6 ) ;
if ( ! V_5 -> V_8 )
goto V_10;
F_3 ( & V_5 -> V_11 , 1 ) ;
F_4 ( & V_5 -> V_12 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_5 -> V_13 = 0 ;
return V_5 ;
V_10:
F_5 ( V_5 ) ;
V_7:
return NULL ;
}
static void F_6 ( struct V_1 * V_5 )
{
F_7 ( V_5 -> V_13 != 0 ) ;
F_5 ( V_5 -> V_8 ) ;
F_5 ( V_5 ) ;
}
static void F_8 ( struct V_1 * V_5 )
{
if ( F_9 ( & V_5 -> V_11 ) )
F_6 ( V_5 ) ;
}
static void F_10 ( const char * V_14 , struct V_15 * V_16 ,
T_1 V_17 , unsigned V_18 , int V_2 ,
int V_3 , unsigned char * V_8 , T_2 V_19 )
{
struct V_20 * V_21 ;
V_21 = F_11 ( NULL , V_6 , V_22 ) ;
if ( V_21 ) {
char V_23 [ sizeof( V_16 -> V_24 ) ] ;
T_1 V_25 = F_12 ( V_16 ) ;
F_13 ( V_21 , L_1
L_2 , V_14 ,
V_16 -> V_26 ,
F_14 ( & V_27 , V_25 ) ,
F_14 ( & V_27 , V_17 ) ,
V_18 ,
V_2 , V_3 ) ;
F_15 ( V_23 , V_16 ) ;
F_16 ( V_21 , V_23 ) ;
F_13 ( V_21 , L_3 ) ;
F_17 ( V_21 , V_8 , V_19 ) ;
F_18 ( V_21 ) ;
}
}
static void F_19 ( struct V_15 * V_16 , T_1 V_17 ,
unsigned int V_18 ,
struct V_1 * V_5 )
{
if ( V_5 -> V_13 == 0 )
return;
if ( V_28 == 0 ) {
V_5 -> V_13 = 0 ;
return;
}
F_10 ( L_4 , V_16 , V_17 , V_18 , V_5 -> V_2 , V_5 -> V_3 ,
V_5 -> V_8 , V_5 -> V_13 ) ;
V_5 -> V_13 = 0 ;
}
static void F_20 ( struct V_1 * V_5 )
{
T_1 V_29 = F_21 ( V_30 ) ;
unsigned int V_18 = F_22 ( V_30 ) ;
F_19 ( V_30 , V_29 , V_18 , V_5 ) ;
}
void F_23 ( void )
{
struct V_1 * V_5 ;
F_24 ( & V_30 -> V_31 -> V_32 ) ;
V_5 = V_30 -> signal -> V_1 ;
V_30 -> signal -> V_1 = NULL ;
F_25 ( & V_30 -> V_31 -> V_32 ) ;
if ( ! V_5 )
return;
F_26 ( & V_5 -> V_12 ) ;
F_20 ( V_5 ) ;
F_27 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_28 ( struct V_33 * V_34 )
{
F_24 ( & V_30 -> V_31 -> V_32 ) ;
V_34 -> V_35 = V_30 -> signal -> V_35 ;
F_25 ( & V_30 -> V_31 -> V_32 ) ;
}
void F_29 ( struct V_36 * V_37 , char V_38 )
{
struct V_1 * V_5 ;
int V_2 , V_3 , V_39 ;
F_24 ( & V_30 -> V_31 -> V_32 ) ;
V_39 = V_30 -> signal -> V_35 ;
V_5 = V_30 -> signal -> V_1 ;
if ( V_5 )
F_30 ( & V_5 -> V_11 ) ;
F_25 ( & V_30 -> V_31 -> V_32 ) ;
V_2 = V_37 -> V_40 -> V_2 ;
V_3 = V_37 -> V_40 -> V_41 + V_37 -> V_42 ;
if ( V_5 ) {
F_26 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_20 ( V_5 ) ;
F_27 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
if ( V_39 && V_28 ) {
T_1 V_29 ;
unsigned int V_18 ;
V_29 = F_21 ( V_30 ) ;
V_18 = F_22 ( V_30 ) ;
F_10 ( L_5 , V_30 , V_29 , V_18 , V_2 ,
V_3 , & V_38 , 1 ) ;
}
}
int F_31 ( struct V_15 * V_16 , T_1 V_17 , T_3 V_18 )
{
struct V_1 * V_5 = F_32 ( - V_43 ) ;
unsigned long V_44 ;
if ( ! F_33 ( V_16 , & V_44 ) )
return - V_45 ;
if ( V_16 -> signal -> V_35 ) {
V_5 = V_16 -> signal -> V_1 ;
if ( V_5 )
F_30 ( & V_5 -> V_11 ) ;
}
F_34 ( V_16 , & V_44 ) ;
if ( ! V_5 || F_35 ( V_5 ) )
return F_36 ( V_5 ) ;
F_26 ( & V_5 -> V_12 ) ;
F_19 ( V_16 , V_17 , V_18 , V_5 ) ;
F_27 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static struct V_1 * F_37 ( struct V_36 * V_37 )
{
struct V_1 * V_5 , * V_46 ;
V_5 = NULL ;
V_46 = NULL ;
F_24 ( & V_30 -> V_31 -> V_32 ) ;
if ( F_38 ( ! V_30 -> signal -> V_35 ) )
goto V_47;
V_5 = V_30 -> signal -> V_1 ;
if ( V_5 ) {
F_30 ( & V_5 -> V_11 ) ;
goto V_47;
}
F_25 ( & V_30 -> V_31 -> V_32 ) ;
V_46 = F_1 ( V_37 -> V_40 -> V_2 ,
V_37 -> V_40 -> V_41 + V_37 -> V_42 ,
V_37 -> V_4 ) ;
if ( V_46 == NULL ) {
F_39 ( L_6 ) ;
return NULL ;
}
F_24 ( & V_30 -> V_31 -> V_32 ) ;
if ( ! V_30 -> signal -> V_35 )
goto V_47;
V_5 = V_30 -> signal -> V_1 ;
if ( ! V_5 ) {
V_30 -> signal -> V_1 = V_46 ;
V_5 = V_46 ;
V_46 = NULL ;
}
F_30 ( & V_5 -> V_11 ) ;
V_47:
F_25 ( & V_30 -> V_31 -> V_32 ) ;
if ( V_46 )
F_6 ( V_46 ) ;
return V_5 ;
}
void F_40 ( struct V_36 * V_37 , unsigned char * V_8 ,
T_2 V_19 )
{
struct V_1 * V_5 ;
int V_2 , V_3 ;
if ( F_41 ( V_19 == 0 ) )
return;
if ( V_37 -> V_40 -> type == V_48
&& V_37 -> V_40 -> V_49 == V_50 )
return;
V_5 = F_37 ( V_37 ) ;
if ( ! V_5 )
return;
F_26 ( & V_5 -> V_12 ) ;
V_2 = V_37 -> V_40 -> V_2 ;
V_3 = V_37 -> V_40 -> V_41 + V_37 -> V_42 ;
if ( V_5 -> V_2 != V_2 || V_5 -> V_3 != V_3
|| V_5 -> V_4 != V_37 -> V_4 ) {
F_20 ( V_5 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_37 -> V_4 ;
}
do {
T_2 V_51 ;
V_51 = V_9 - V_5 -> V_13 ;
if ( V_51 > V_19 )
V_51 = V_19 ;
memcpy ( V_5 -> V_8 + V_5 -> V_13 , V_8 , V_51 ) ;
V_5 -> V_13 += V_51 ;
V_8 += V_51 ;
V_19 -= V_51 ;
if ( V_5 -> V_13 == V_9 )
F_20 ( V_5 ) ;
} while ( V_19 != 0 );
F_27 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_42 ( struct V_36 * V_37 )
{
struct V_1 * V_5 ;
F_24 ( & V_30 -> V_31 -> V_32 ) ;
if ( F_38 ( ! V_30 -> signal -> V_35 ) ) {
F_25 ( & V_30 -> V_31 -> V_32 ) ;
return;
}
V_5 = V_30 -> signal -> V_1 ;
if ( V_5 )
F_30 ( & V_5 -> V_11 ) ;
F_25 ( & V_30 -> V_31 -> V_32 ) ;
if ( V_5 ) {
int V_2 , V_3 ;
V_2 = V_37 -> V_40 -> V_2 ;
V_3 = V_37 -> V_40 -> V_41 + V_37 -> V_42 ;
F_26 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_20 ( V_5 ) ;
F_27 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
}
