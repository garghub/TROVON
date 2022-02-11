int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
int V_5 , V_6 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
V_5 = F_4 ( V_2 -> V_8 , V_2 -> V_9 , V_6 ) ;
F_5 ( & V_2 -> V_7 , V_4 ) ;
F_6 ( L_1 ,
V_3 , V_6 , V_5 ) ;
return V_5 ;
}
void F_7 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
unsigned long V_4 ;
int V_6 = F_2 ( V_3 ) ;
F_6 ( L_2 ,
V_3 , V_6 , V_5 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
F_8 ( V_2 -> V_8 , V_5 , V_6 ) ;
F_5 ( & V_2 -> V_7 , V_4 ) ;
}
void F_9 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned long V_4 ;
F_6 ( L_3 , V_10 ) ;
F_3 ( & V_2 -> V_7 , V_4 ) ;
F_10 ( V_2 -> V_8 , V_10 , 0 ) ;
F_5 ( & V_2 -> V_7 , V_4 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_11 , V_12 , V_13 ;
const T_1 * V_14 ;
if ( ! V_2 -> V_15 )
return 1 ;
V_14 = F_12 ( V_2 -> V_15 , L_4 , & V_13 ) ;
if ( ! V_14 ) {
F_6 ( L_5 \
L_6 , V_2 -> V_15 -> V_16 ) ;
return 1 ;
}
if ( V_13 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_13 ( V_17 L_7
L_8 , V_2 -> V_15 -> V_16 ) ;
return - V_18 ;
}
F_10 ( V_2 -> V_8 , 0 , F_2 ( V_2 -> V_9 ) ) ;
F_14 ( & V_2 -> V_7 ) ;
V_13 /= 2 * sizeof( T_1 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ , V_14 += 2 ) {
for ( V_12 = 0 ; V_12 < * ( V_14 + 1 ) ; V_12 ++ )
F_8 ( V_2 -> V_8 , * V_14 + V_12 , 0 ) ;
}
F_15 ( & V_2 -> V_7 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , unsigned int V_9 ,
struct V_19 * V_15 )
{
int V_20 ;
if ( ! V_9 )
return - V_18 ;
V_20 = F_17 ( V_9 ) * sizeof( long ) ;
F_6 ( L_9 , V_20 ) ;
V_2 -> V_8 = F_18 ( V_20 , V_21 ) ;
if ( ! V_2 -> V_8 ) {
F_6 ( L_10 ) ;
return - V_22 ;
}
F_19 ( & V_2 -> V_7 ) ;
V_2 -> V_15 = F_20 ( V_15 ) ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_15 ) ;
V_2 -> V_8 = NULL ;
}
void T_2 F_23 ( void )
{
struct V_1 V_2 ;
int V_11 , V_20 = 512 ;
F_24 ( F_16 ( & V_2 , 0 , NULL ) != 0 ) ;
F_24 ( 0 == F_16 ( & V_2 , V_20 , NULL ) ) ;
F_24 ( 0 == F_4 ( V_2 . V_8 , V_20 ,
F_2 ( V_20 ) ) ) ;
F_8 ( V_2 . V_8 , 0 , F_2 ( V_20 ) ) ;
F_24 ( F_11 ( & V_2 ) > 0 ) ;
F_24 ( 0 == F_4 ( V_2 . V_8 , V_20 ,
F_2 ( V_20 ) ) ) ;
F_8 ( V_2 . V_8 , 0 , F_2 ( V_20 ) ) ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ )
F_24 ( F_1 ( & V_2 , 1 ) >= 0 ) ;
F_24 ( F_1 ( & V_2 , 1 ) < 0 ) ;
F_24 ( F_4 ( V_2 . V_8 , V_20 , 0 ) < 0 ) ;
F_7 ( & V_2 , V_20 / 2 , 1 ) ;
F_24 ( F_1 ( & V_2 , 1 ) == V_20 / 2 ) ;
F_21 ( & V_2 ) ;
F_24 ( V_2 . V_8 == NULL ) ;
F_25 ( V_2 . V_8 ) ;
}
void T_2 F_26 ( void )
{
T_1 V_23 [] = { 10 , 10 , 25 , 3 , 40 , 1 , 100 , 100 , 200 , 20 } ;
const char * V_24 = L_11 ;
char * V_25 = L_4 ;
char * V_26 = L_12 ;
struct V_19 V_15 ;
struct V_27 V_28 ;
struct V_1 V_2 ;
int V_20 = 256 ;
F_27 ( V_29 , V_20 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
F_28 ( & V_15 ) ;
V_15 . V_16 = V_26 ;
F_24 ( 0 == F_16 ( & V_2 , V_20 , & V_15 ) ) ;
F_24 ( F_11 ( & V_2 ) > 0 ) ;
F_24 ( 0 == F_4 ( V_2 . V_8 , V_20 ,
F_2 ( V_20 ) ) ) ;
F_8 ( V_2 . V_8 , 0 , F_2 ( V_20 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_30 = V_25 ;
V_28 . V_31 = & V_23 ;
V_28 . V_32 = sizeof( V_23 ) ;
V_15 . V_33 = & V_28 ;
F_24 ( F_11 ( & V_2 ) == 0 ) ;
F_24 ( 0 == F_29 ( V_24 , V_29 , V_20 ) ) ;
F_24 ( F_30 ( V_29 , V_2 . V_8 , V_20 ) ) ;
F_21 ( & V_2 ) ;
F_25 ( V_2 . V_8 ) ;
}
int T_2 F_31 ( void )
{
F_13 ( V_34 L_13 ) ;
F_23 () ;
F_26 () ;
return 0 ;
}
