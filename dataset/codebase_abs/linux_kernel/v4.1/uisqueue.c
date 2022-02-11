unsigned char F_1 ( struct V_1 T_1 * V_2 , T_2 V_3 ,
void * V_4 )
{
void T_1 * V_5 ;
unsigned int V_6 , V_7 , V_8 ;
struct V_9 T_1 * V_10 =
(struct V_9 T_1 * )
( ( char T_1 * ) V_2 + F_2 ( & V_2 -> V_11 ) )
+ V_3 ;
V_6 = F_3 ( & V_10 -> V_6 ) ;
V_7 = F_3 ( & V_10 -> V_7 ) ;
if ( ( ( V_6 + 1 ) % F_3 ( & V_10 -> V_12 ) ) == V_7 ) {
V_8 = F_2 ( & V_10 -> V_13 ) + 1 ;
F_4 ( V_8 , & V_10 -> V_13 ) ;
return 0 ;
}
V_6 = ( V_6 + 1 ) % F_3 ( & V_10 -> V_12 ) ;
V_5 = ( char T_1 * ) V_10 + F_2 ( & V_10 -> V_14 ) +
( V_6 * F_3 ( & V_10 -> V_15 ) ) ;
F_5 ( V_5 , V_4 , F_3 ( & V_10 -> V_15 ) ) ;
F_6 () ;
F_7 ( V_6 , & V_10 -> V_6 ) ;
F_4 ( F_2 ( & V_10 -> V_16 ) + 1 , & V_10 -> V_16 ) ;
return 1 ;
}
unsigned char
F_8 ( struct V_1 T_1 * V_2 , T_2 V_3 , void * V_4 )
{
void T_1 * V_17 ;
unsigned int V_6 , V_7 ;
struct V_9 T_1 * V_10 =
(struct V_9 T_1 * ) ( ( char T_1 * ) V_2 +
F_2 ( & V_2 -> V_11 ) ) + V_3 ;
V_6 = F_3 ( & V_10 -> V_6 ) ;
V_7 = F_3 ( & V_10 -> V_7 ) ;
if ( V_6 == V_7 ) {
F_4 ( F_2 ( & V_10 -> V_18 ) + 1 , & V_10 -> V_18 ) ;
return 0 ;
}
V_7 = ( V_7 + 1 ) % F_3 ( & V_10 -> V_12 ) ;
V_17 = ( char T_1 * ) V_10 + F_2 ( & V_10 -> V_14 ) +
( V_7 * F_3 ( & V_10 -> V_15 ) ) ;
F_9 ( V_4 , V_17 , F_3 ( & V_10 -> V_15 ) ) ;
F_6 () ;
F_7 ( V_7 , & V_10 -> V_7 ) ;
F_4 ( F_2 ( & V_10 -> V_19 ) + 1 ,
& V_10 -> V_19 ) ;
return 1 ;
}
unsigned int F_10 ( struct V_1 * V_2 , T_2 V_3 ,
void * V_4 )
{
void * V_17 ;
unsigned int V_6 , V_7 , V_20 = 0 ;
struct V_9 * V_10 =
(struct V_9 * ) ( ( char * ) V_2 +
V_2 -> V_11 ) + V_3 ;
V_6 = V_10 -> V_6 ;
V_7 = V_10 -> V_7 ;
if ( V_6 == V_7 )
return 0 ;
while ( V_6 != V_7 ) {
V_7 = ( V_7 + 1 ) % V_10 -> V_12 ;
V_17 =
( char * ) V_10 + V_10 -> V_14 +
( V_7 * V_10 -> V_15 ) ;
memcpy ( ( char * ) V_4 + ( V_10 -> V_15 * V_20 ) ,
V_17 , V_10 -> V_15 ) ;
F_6 () ;
V_10 -> V_7 = V_7 ;
V_20 ++ ;
V_10 -> V_19 ++ ;
}
return V_20 ;
}
unsigned char F_11 ( struct V_1 T_1 * V_2 ,
T_2 V_3 )
{
struct V_9 T_1 * V_10 =
(struct V_9 T_1 * ) ( ( char T_1 * ) V_2 +
F_2 ( & V_2 -> V_11 ) ) + V_3 ;
return F_3 ( & V_10 -> V_6 ) == F_3 ( & V_10 -> V_7 ) ;
}
unsigned long long
F_12 ( unsigned long long T_1 * V_21 ,
unsigned long long V_22 )
{
unsigned long long V_23 ;
unsigned long long V_24 ;
V_24 = F_2 ( V_21 ) ;
do {
V_23 = V_24 ;
V_24 = F_13 ( ( V_25 unsigned long long * ) V_21 , V_23 , V_23 | V_22 ) ;
} while ( V_23 != V_24 );
return V_24 ;
}
unsigned long long
F_14 ( unsigned long long T_1 * V_21 ,
unsigned long long V_22 )
{
unsigned long long V_23 ;
unsigned long long V_24 ;
V_24 = F_2 ( V_21 ) ;
do {
V_23 = V_24 ;
V_24 = F_13 ( ( V_25 unsigned long long * ) V_21 , V_23 , V_23 & V_22 ) ;
} while ( V_23 != V_24 );
return V_24 ;
}
static T_3
F_15 ( struct V_26 * V_27 ,
unsigned int V_28 ,
void * signal ,
T_4 * V_29 ,
T_3 * V_30 )
{
unsigned long V_31 ;
T_3 V_32 = 0 ;
F_16 ( V_29 , V_31 ) ;
if ( ! F_17 ( V_27 -> V_33 , V_30 ) )
goto V_34;
if ( F_1 ( V_27 -> V_33 , V_28 , signal ) ) {
V_27 -> V_35 ++ ;
V_32 = 1 ;
}
F_18 ( V_27 -> V_33 , V_30 ) ;
V_34:
F_19 ( ( T_4 * ) V_29 , V_31 ) ;
return V_32 ;
}
int
F_20 ( struct V_26 * V_27 ,
struct V_36 * V_37 ,
unsigned int V_28 ,
void * V_38 ,
unsigned char V_39 ,
T_5 V_40 ,
char V_41 , T_3 * V_30 )
{
while ( ! F_15 ( V_27 , V_28 , V_37 ,
( T_4 * ) V_38 ,
V_30 ) ) {
if ( V_41 != V_42 )
return 0 ;
F_21 ( V_43 ) ;
F_22 ( F_23 ( 10 ) ) ;
}
return 1 ;
}
int
F_24 ( struct V_26 * V_27 ,
void * V_37 , unsigned int V_28 )
{
if ( ! F_8 ( V_27 -> V_33 , V_28 , V_37 ) )
return 0 ;
V_27 -> V_44 ++ ;
return 1 ;
}
