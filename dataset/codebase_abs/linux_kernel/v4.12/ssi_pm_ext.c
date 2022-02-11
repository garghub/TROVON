void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) F_2 ( V_2 ) ;
unsigned int V_5 ;
void T_1 * V_6 = V_4 -> V_6 ;
unsigned int V_7 = 0 ;
F_3 ( F_4 ( V_8 , V_9 ) , V_7 ) ;
for (; V_7 < V_10 ; V_7 += 4 ) {
F_3 ( F_4 ( V_8 , V_11 ) , 0x0 ) ;
do {
V_5 = F_5 ( F_4 ( V_8 , V_12 ) ) ;
} while ( ! ( V_5 & 0x1 ) );
}
}
void F_6 ( struct V_1 * V_2 )
{
return;
}
