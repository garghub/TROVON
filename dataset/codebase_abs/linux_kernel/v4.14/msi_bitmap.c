int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
int V_5 , V_6 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
V_5 = F_4 ( V_2 -> V_8 , V_2 -> V_9 , 0 ,
V_3 , ( 1 << V_6 ) - 1 ) ;
if ( V_5 > V_2 -> V_9 )
goto V_10;
F_5 ( V_2 -> V_8 , V_5 , V_3 ) ;
F_6 ( & V_2 -> V_7 , V_4 ) ;
F_7 ( L_1 , V_3 , V_5 ) ;
return V_5 ;
V_10:
F_6 ( & V_2 -> V_7 , V_4 ) ;
return - V_11 ;
}
void F_8 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
unsigned long V_4 ;
F_7 ( L_2 ,
V_3 , V_5 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
F_9 ( V_2 -> V_8 , V_5 , V_3 ) ;
F_6 ( & V_2 -> V_7 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 , unsigned int V_12 )
{
unsigned long V_4 ;
F_7 ( L_3 , V_12 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
F_11 ( V_2 -> V_8 , V_12 , 0 ) ;
F_6 ( & V_2 -> V_7 , V_4 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_13 , V_14 , V_15 ;
const T_1 * V_16 ;
if ( ! V_2 -> V_17 )
return 1 ;
V_16 = F_13 ( V_2 -> V_17 , L_4 , & V_15 ) ;
if ( ! V_16 ) {
F_7 ( L_5 \
L_6 , V_2 -> V_17 ) ;
return 1 ;
}
if ( V_15 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_14 ( V_18 L_7
L_8 , V_2 -> V_17 ) ;
return - V_19 ;
}
F_11 ( V_2 -> V_8 , 0 , F_2 ( V_2 -> V_9 ) ) ;
F_15 ( & V_2 -> V_7 ) ;
V_15 /= 2 * sizeof( T_1 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ , V_16 += 2 ) {
for ( V_14 = 0 ; V_14 < * ( V_16 + 1 ) ; V_14 ++ )
F_16 ( V_2 -> V_8 , * V_16 + V_14 , 0 ) ;
}
F_17 ( & V_2 -> V_7 ) ;
return 0 ;
}
int T_2 F_18 ( struct V_1 * V_2 , unsigned int V_9 ,
struct V_20 * V_17 )
{
int V_21 ;
if ( ! V_9 )
return - V_19 ;
V_21 = F_19 ( V_9 ) * sizeof( long ) ;
F_7 ( L_9 , V_21 ) ;
V_2 -> V_22 = F_20 () ;
if ( V_2 -> V_22 )
V_2 -> V_8 = F_21 ( V_21 , V_23 ) ;
else {
V_2 -> V_8 = F_22 ( V_21 , 0 ) ;
F_23 ( V_2 -> V_8 ) ;
}
if ( ! V_2 -> V_8 ) {
F_7 ( L_10 ) ;
return - V_11 ;
}
F_24 ( & V_2 -> V_7 ) ;
V_2 -> V_17 = F_25 ( V_17 ) ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 )
F_27 ( V_2 -> V_8 ) ;
F_28 ( V_2 -> V_17 ) ;
V_2 -> V_8 = NULL ;
}
static void T_3 F_29 ( void )
{
struct V_1 V_2 ;
int V_24 , V_13 , V_21 = 512 ;
F_30 ( F_18 ( & V_2 , 0 , NULL ) == 0 ) ;
F_30 ( F_18 ( & V_2 , V_21 , NULL ) ) ;
F_30 ( F_31 ( V_2 . V_8 , V_21 , F_2 ( V_21 ) ) ) ;
F_16 ( V_2 . V_8 , 0 , F_2 ( V_21 ) ) ;
F_30 ( F_12 ( & V_2 ) <= 0 ) ;
F_30 ( F_31 ( V_2 . V_8 , V_21 , F_2 ( V_21 ) ) ) ;
F_16 ( V_2 . V_8 , 0 , F_2 ( V_21 ) ) ;
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ )
F_30 ( F_1 ( & V_2 , 1 ) < 0 ) ;
F_30 ( F_1 ( & V_2 , 1 ) >= 0 ) ;
F_30 ( F_31 ( V_2 . V_8 , V_21 , 0 ) >= 0 ) ;
F_8 ( & V_2 , V_21 / 2 , 1 ) ;
F_30 ( F_1 ( & V_2 , 1 ) != V_21 / 2 ) ;
F_8 ( & V_2 , 3 , V_21 - 3 ) ;
V_24 = F_1 ( & V_2 , 2 ) ;
F_30 ( V_24 < 0 && V_24 % 2 != 0 ) ;
V_24 = F_1 ( & V_2 , 4 ) ;
F_30 ( V_24 < 0 && V_24 % 4 != 0 ) ;
V_24 = F_1 ( & V_2 , 8 ) ;
F_30 ( V_24 < 0 && V_24 % 8 != 0 ) ;
V_24 = F_1 ( & V_2 , 9 ) ;
F_30 ( V_24 < 0 && V_24 % 16 != 0 ) ;
V_24 = F_1 ( & V_2 , 3 ) ;
F_30 ( V_24 < 0 && V_24 % 4 != 0 ) ;
V_24 = F_1 ( & V_2 , 7 ) ;
F_30 ( V_24 < 0 && V_24 % 8 != 0 ) ;
V_24 = F_1 ( & V_2 , 121 ) ;
F_30 ( V_24 < 0 && V_24 % 128 != 0 ) ;
F_26 ( & V_2 ) ;
F_30 ( V_2 . V_8 != NULL ) ;
}
static void T_3 F_32 ( void )
{
T_1 V_25 [] = { 10 , 10 , 25 , 3 , 40 , 1 , 100 , 100 , 200 , 20 } ;
const char * V_26 = L_11 ;
char * V_27 = L_4 ;
char * V_28 = L_12 ;
struct V_20 V_17 ;
struct V_29 V_30 ;
struct V_1 V_2 ;
int V_21 = 256 ;
F_33 ( V_31 , V_21 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
F_34 ( & V_17 ) ;
V_17 . V_32 = V_28 ;
F_30 ( F_18 ( & V_2 , V_21 , & V_17 ) ) ;
F_30 ( F_12 ( & V_2 ) <= 0 ) ;
F_30 ( F_31 ( V_2 . V_8 , V_21 , F_2 ( V_21 ) ) ) ;
F_16 ( V_2 . V_8 , 0 , F_2 ( V_21 ) ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_33 = V_27 ;
V_30 . V_34 = & V_25 ;
V_30 . V_35 = sizeof( V_25 ) ;
V_17 . V_36 = & V_30 ;
F_30 ( F_12 ( & V_2 ) ) ;
F_30 ( F_35 ( V_26 , V_31 , V_21 ) ) ;
F_30 ( ! F_36 ( V_31 , V_2 . V_8 , V_21 ) ) ;
F_26 ( & V_2 ) ;
F_27 ( V_2 . V_8 ) ;
}
static int T_3 F_37 ( void )
{
F_14 ( V_37 L_13 ) ;
F_29 () ;
F_32 () ;
return 0 ;
}
