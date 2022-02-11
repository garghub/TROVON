static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_6 -> V_7 + V_8 + V_3 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_9 , V_6 -> V_7 + V_8 + V_3 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_11 , V_12 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
F_4 ( V_2 , V_13 , V_4 | F_7 ( 13 ) ) ;
F_4 ( V_2 , V_10 , V_4 | F_7 ( 11 ) ) ;
do {
V_4 = F_1 ( V_2 , V_15 ) ;
} while ( ( V_4 & V_16 ) == V_17 );
V_4 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_10 , V_4 & ~ F_7 ( 11 ) ) ;
do {
V_4 = F_1 ( V_2 , V_15 ) ;
} while ( ( V_4 & V_16 ) != V_17 );
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_4 ;
F_4 ( V_2 , V_11 , V_12 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
V_4 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_10 , V_4 & ~ F_7 ( 13 ) ) ;
V_4 = F_1 ( V_2 , V_18 ) ;
F_4 ( V_2 , V_18 , V_4 | F_7 ( 6 ) ) ;
F_4 ( V_2 , V_18 , V_4 & ~ F_7 ( 13 ) ) ;
V_4 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_10 , V_4 | F_7 ( 11 ) ) ;
do {
V_4 = F_1 ( V_2 , V_15 ) ;
} while ( ( V_4 & V_16 ) != V_17 );
V_4 = F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_10 , V_4 & ~ F_7 ( 11 ) ) ;
V_4 = F_1 ( V_2 , V_18 ) ;
F_4 ( V_2 , V_18 , V_4 | F_7 ( 12 ) ) ;
return 0 ;
}
