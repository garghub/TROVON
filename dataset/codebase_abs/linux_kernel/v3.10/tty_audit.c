static struct V_1 * F_1 ( int V_2 , int V_3 ,
unsigned V_4 )
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
static void F_10 ( const char * V_14 , int V_2 , int V_3 ,
unsigned char * V_8 , T_1 V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = V_20 ;
T_2 V_21 = F_11 ( & V_22 , F_12 ( V_19 ) ) ;
T_2 V_23 = F_11 ( & V_22 , F_13 ( V_19 ) ) ;
T_3 V_24 = F_14 ( V_19 ) ;
V_17 = F_15 ( NULL , V_6 , V_25 ) ;
if ( V_17 ) {
char V_26 [ sizeof( V_19 -> V_27 ) ] ;
F_16 ( V_17 , L_1
L_2 , V_14 , V_19 -> V_28 , V_21 ,
V_23 , V_24 , V_2 , V_3 ) ;
F_17 ( V_26 , V_19 ) ;
F_18 ( V_17 , V_26 ) ;
F_16 ( V_17 , L_3 ) ;
F_19 ( V_17 , V_8 , V_15 ) ;
F_20 ( V_17 ) ;
}
}
static void F_21 ( struct V_1 * V_5 )
{
if ( V_5 -> V_13 == 0 )
return;
if ( V_29 == 0 ) {
V_5 -> V_13 = 0 ;
return;
}
F_10 ( L_4 , V_5 -> V_2 , V_5 -> V_3 , V_5 -> V_8 , V_5 -> V_13 ) ;
V_5 -> V_13 = 0 ;
}
void F_22 ( void )
{
struct V_1 * V_5 ;
V_5 = V_20 -> signal -> V_1 ;
V_20 -> signal -> V_1 = NULL ;
if ( ! V_5 )
return;
F_23 ( & V_5 -> V_12 ) ;
F_21 ( V_5 ) ;
F_24 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_25 ( struct V_30 * V_31 )
{
V_31 -> V_32 = V_20 -> signal -> V_32 ;
V_31 -> V_33 = V_20 -> signal -> V_33 ;
}
void F_26 ( struct V_34 * V_35 , char V_36 )
{
struct V_1 * V_5 ;
int V_2 , V_3 , V_37 ;
unsigned long V_38 ;
F_27 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
V_37 = V_20 -> signal -> V_32 ;
V_5 = V_20 -> signal -> V_1 ;
if ( V_5 )
F_28 ( & V_5 -> V_11 ) ;
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
V_2 = V_35 -> V_41 -> V_2 ;
V_3 = V_35 -> V_41 -> V_42 + V_35 -> V_43 ;
if ( V_5 ) {
F_23 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_21 ( V_5 ) ;
F_24 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
if ( V_37 && V_29 ) {
T_4 V_44 ;
unsigned int V_24 ;
V_44 = F_13 ( V_20 ) ;
V_24 = F_14 ( V_20 ) ;
F_10 ( L_5 , V_2 , V_3 , & V_36 , 1 ) ;
}
}
int F_30 ( void )
{
struct V_1 * V_5 = F_31 ( - V_45 ) ;
struct V_18 * V_19 = V_20 ;
unsigned long V_38 ;
if ( ! F_32 ( V_19 , & V_38 ) )
return - V_46 ;
if ( V_19 -> signal -> V_32 ) {
V_5 = V_19 -> signal -> V_1 ;
if ( V_5 )
F_28 ( & V_5 -> V_11 ) ;
}
F_33 ( V_19 , & V_38 ) ;
if ( ! V_5 || F_34 ( V_5 ) )
return F_35 ( V_5 ) ;
F_23 ( & V_5 -> V_12 ) ;
F_21 ( V_5 ) ;
F_24 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static struct V_1 * F_36 ( struct V_34 * V_35 ,
unsigned V_4 )
{
struct V_1 * V_5 , * V_47 ;
unsigned long V_38 ;
V_5 = NULL ;
V_47 = NULL ;
F_27 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( F_37 ( ! V_20 -> signal -> V_32 ) )
goto V_48;
V_5 = V_20 -> signal -> V_1 ;
if ( V_5 ) {
F_28 ( & V_5 -> V_11 ) ;
goto V_48;
}
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
V_47 = F_1 ( V_35 -> V_41 -> V_2 ,
V_35 -> V_41 -> V_42 + V_35 -> V_43 ,
V_4 ) ;
if ( V_47 == NULL ) {
F_38 ( L_6 ) ;
return NULL ;
}
F_27 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( ! V_20 -> signal -> V_32 )
goto V_48;
V_5 = V_20 -> signal -> V_1 ;
if ( ! V_5 ) {
V_20 -> signal -> V_1 = V_47 ;
V_5 = V_47 ;
V_47 = NULL ;
}
F_28 ( & V_5 -> V_11 ) ;
V_48:
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( V_47 )
F_6 ( V_47 ) ;
return V_5 ;
}
void F_39 ( struct V_34 * V_35 , unsigned char * V_8 ,
T_1 V_15 , unsigned V_4 )
{
struct V_1 * V_5 ;
int V_2 , V_3 ;
int V_49 ;
unsigned long V_38 ;
if ( F_40 ( V_15 == 0 ) )
return;
F_27 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
V_49 = V_20 -> signal -> V_33 ;
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( ! V_49 && V_4 && ! F_41 ( V_35 ) )
return;
if ( V_35 -> V_41 -> type == V_50
&& V_35 -> V_41 -> V_51 == V_52 )
return;
V_5 = F_36 ( V_35 , V_4 ) ;
if ( ! V_5 )
return;
F_23 ( & V_5 -> V_12 ) ;
V_2 = V_35 -> V_41 -> V_2 ;
V_3 = V_35 -> V_41 -> V_42 + V_35 -> V_43 ;
if ( V_5 -> V_2 != V_2 || V_5 -> V_3 != V_3
|| V_5 -> V_4 != V_4 ) {
F_21 ( V_5 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
}
do {
T_1 V_53 ;
V_53 = V_9 - V_5 -> V_13 ;
if ( V_53 > V_15 )
V_53 = V_15 ;
memcpy ( V_5 -> V_8 + V_5 -> V_13 , V_8 , V_53 ) ;
V_5 -> V_13 += V_53 ;
V_8 += V_53 ;
V_15 -= V_53 ;
if ( V_5 -> V_13 == V_9 )
F_21 ( V_5 ) ;
} while ( V_15 != 0 );
F_24 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
void F_42 ( struct V_34 * V_35 )
{
struct V_1 * V_5 ;
unsigned long V_38 ;
F_27 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( F_37 ( ! V_20 -> signal -> V_32 ) ) {
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
return;
}
V_5 = V_20 -> signal -> V_1 ;
if ( V_5 )
F_28 ( & V_5 -> V_11 ) ;
F_29 ( & V_20 -> V_39 -> V_40 , V_38 ) ;
if ( V_5 ) {
int V_2 , V_3 ;
V_2 = V_35 -> V_41 -> V_2 ;
V_3 = V_35 -> V_41 -> V_42 + V_35 -> V_43 ;
F_23 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_2 == V_2 && V_5 -> V_3 == V_3 )
F_21 ( V_5 ) ;
F_24 ( & V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
}
}
