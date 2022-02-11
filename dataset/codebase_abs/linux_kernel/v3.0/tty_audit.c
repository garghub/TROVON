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
V_16 -> V_26 , V_25 , V_17 , V_18 ,
V_2 , V_3 ) ;
F_14 ( V_23 , V_16 ) ;
F_15 ( V_21 , V_23 ) ;
F_13 ( V_21 , L_3 ) ;
F_16 ( V_21 , V_8 , V_19 ) ;
F_17 ( V_21 ) ;
}
}
static void F_18 ( struct V_15 * V_16 , T_1 V_17 ,
unsigned int V_18 ,
struct V_1 * V_5 )
{
if ( V_5 -> V_13 == 0 )
return;
if ( V_27 == 0 ) {
V_5 -> V_13 = 0 ;
return;
}
F_10 ( L_4 , V_16 , V_17 , V_18 , V_5 -> V_2 , V_5 -> V_3 ,
V_5 -> V_8 , V_5 -> V_13 ) ;
V_5 -> V_13 = 0 ;
}
static void F_19 ( struct V_1 * V_5 )
{
T_1 V_28 = F_20 ( V_29 ) ;
unsigned int V_18 = F_21 ( V_29 ) ;
F_18 ( V_29 , V_28 , V_18 , V_5 ) ;
}
void F_22 ( void )
{
struct V_1 * V_5 ;
F_23 ( & V_29 -> V_30 -> V_31 ) ;
V_5 = V_29 -> signal -> V_1 ;
V_29 -> signal -> V_1 = NULL ;
F_24 ( & V_29 -> V_30 -> V_31 ) ;
if ( ! V_5 )
return;
F_25 ( & V_5 -> V_12 ) ;
F_19 ( V_5 ) ;
F_26 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_27 ( struct V_32 * V_33 )
{
F_23 ( & V_29 -> V_30 -> V_31 ) ;
V_33 -> V_34 = V_29 -> signal -> V_34 ;
F_24 ( & V_29 -> V_30 -> V_31 ) ;
}
void F_28 ( struct V_35 * V_36 , char V_37 )
{
struct V_1 * V_5 ;
int V_2 , V_3 , V_38 ;
F_23 ( & V_29 -> V_30 -> V_31 ) ;
V_38 = V_29 -> signal -> V_34 ;
V_5 = V_29 -> signal -> V_1 ;
if ( V_5 )
F_29 ( & V_5 -> V_11 ) ;
F_24 ( & V_29 -> V_30 -> V_31 ) ;
V_2 = V_36 -> V_39 -> V_2 ;
V_3 = V_36 -> V_39 -> V_40 + V_36 -> V_41 ;
if ( V_5 ) {
F_25 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_19 ( V_5 ) ;
F_26 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
if ( V_38 && V_27 ) {
T_1 V_28 ;
unsigned int V_18 ;
V_28 = F_20 ( V_29 ) ;
V_18 = F_21 ( V_29 ) ;
F_10 ( L_5 , V_29 , V_28 , V_18 , V_2 ,
V_3 , & V_37 , 1 ) ;
}
}
int F_30 ( struct V_15 * V_16 , T_1 V_17 , T_3 V_18 )
{
struct V_1 * V_5 = F_31 ( - V_42 ) ;
unsigned long V_43 ;
if ( ! F_32 ( V_16 , & V_43 ) )
return - V_44 ;
if ( V_16 -> signal -> V_34 ) {
V_5 = V_16 -> signal -> V_1 ;
if ( V_5 )
F_29 ( & V_5 -> V_11 ) ;
}
F_33 ( V_16 , & V_43 ) ;
if ( ! V_5 || F_34 ( V_5 ) )
return F_35 ( V_5 ) ;
F_25 ( & V_5 -> V_12 ) ;
F_18 ( V_16 , V_17 , V_18 , V_5 ) ;
F_26 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static struct V_1 * F_36 ( struct V_35 * V_36 )
{
struct V_1 * V_5 , * V_45 ;
V_5 = NULL ;
V_45 = NULL ;
F_23 ( & V_29 -> V_30 -> V_31 ) ;
if ( F_37 ( ! V_29 -> signal -> V_34 ) )
goto V_46;
V_5 = V_29 -> signal -> V_1 ;
if ( V_5 ) {
F_29 ( & V_5 -> V_11 ) ;
goto V_46;
}
F_24 ( & V_29 -> V_30 -> V_31 ) ;
V_45 = F_1 ( V_36 -> V_39 -> V_2 ,
V_36 -> V_39 -> V_40 + V_36 -> V_41 ,
V_36 -> V_4 ) ;
if ( V_45 == NULL ) {
F_38 ( L_6 ) ;
return NULL ;
}
F_23 ( & V_29 -> V_30 -> V_31 ) ;
if ( ! V_29 -> signal -> V_34 )
goto V_46;
V_5 = V_29 -> signal -> V_1 ;
if ( ! V_5 ) {
V_29 -> signal -> V_1 = V_45 ;
V_5 = V_45 ;
V_45 = NULL ;
}
F_29 ( & V_5 -> V_11 ) ;
V_46:
F_24 ( & V_29 -> V_30 -> V_31 ) ;
if ( V_45 )
F_6 ( V_45 ) ;
return V_5 ;
}
void F_39 ( struct V_35 * V_36 , unsigned char * V_8 ,
T_2 V_19 )
{
struct V_1 * V_5 ;
int V_2 , V_3 ;
if ( F_40 ( V_19 == 0 ) )
return;
if ( V_36 -> V_39 -> type == V_47
&& V_36 -> V_39 -> V_48 == V_49 )
return;
V_5 = F_36 ( V_36 ) ;
if ( ! V_5 )
return;
F_25 ( & V_5 -> V_12 ) ;
V_2 = V_36 -> V_39 -> V_2 ;
V_3 = V_36 -> V_39 -> V_40 + V_36 -> V_41 ;
if ( V_5 -> V_2 != V_2 || V_5 -> V_3 != V_3
|| V_5 -> V_4 != V_36 -> V_4 ) {
F_19 ( V_5 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_36 -> V_4 ;
}
do {
T_2 V_50 ;
V_50 = V_9 - V_5 -> V_13 ;
if ( V_50 > V_19 )
V_50 = V_19 ;
memcpy ( V_5 -> V_8 + V_5 -> V_13 , V_8 , V_50 ) ;
V_5 -> V_13 += V_50 ;
V_8 += V_50 ;
V_19 -= V_50 ;
if ( V_5 -> V_13 == V_9 )
F_19 ( V_5 ) ;
} while ( V_19 != 0 );
F_26 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_41 ( struct V_35 * V_36 )
{
struct V_1 * V_5 ;
F_23 ( & V_29 -> V_30 -> V_31 ) ;
if ( F_37 ( ! V_29 -> signal -> V_34 ) ) {
F_24 ( & V_29 -> V_30 -> V_31 ) ;
return;
}
V_5 = V_29 -> signal -> V_1 ;
if ( V_5 )
F_29 ( & V_5 -> V_11 ) ;
F_24 ( & V_29 -> V_30 -> V_31 ) ;
if ( V_5 ) {
int V_2 , V_3 ;
V_2 = V_36 -> V_39 -> V_2 ;
V_3 = V_36 -> V_39 -> V_40 + V_36 -> V_41 ;
F_25 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_19 ( V_5 ) ;
F_26 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
}
