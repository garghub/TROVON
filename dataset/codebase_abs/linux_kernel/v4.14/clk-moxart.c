static void T_1 F_1 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
const char * V_9 = V_2 -> V_9 ;
const char * V_10 ;
F_2 ( V_2 , L_1 , & V_9 ) ;
V_10 = F_3 ( V_2 , 0 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_5 ( L_2 , V_2 ) ;
return;
}
V_8 = F_6 ( V_3 + 0x30 ) >> 3 & 0x3f ;
F_7 ( V_3 ) ;
V_7 = F_8 ( V_2 , 0 ) ;
if ( F_9 ( V_7 ) ) {
F_5 ( L_3 , V_2 ) ;
return;
}
V_5 = F_10 ( NULL , V_9 , V_10 , 0 , V_8 , 1 ) ;
if ( F_9 ( V_5 ) ) {
F_5 ( L_4 , V_2 ) ;
return;
}
F_11 ( V_5 , NULL , V_9 ) ;
F_12 ( V_2 , V_11 , V_5 ) ;
}
static void T_1 F_13 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_12 ;
unsigned int div , V_13 ;
unsigned int V_14 [] = { 2 , 3 , 4 , 6 , 8 } ;
const char * V_9 = V_2 -> V_9 ;
const char * V_10 ;
F_2 ( V_2 , L_1 , & V_9 ) ;
V_10 = F_3 ( V_2 , 0 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_5 ( L_2 , V_2 ) ;
return;
}
V_13 = F_6 ( V_3 + 0xc ) >> 4 & 0x7 ;
F_7 ( V_3 ) ;
if ( V_13 > 4 )
V_13 = 0 ;
div = V_14 [ V_13 ] * 2 ;
V_12 = F_8 ( V_2 , 0 ) ;
if ( F_9 ( V_12 ) ) {
F_5 ( L_3 , V_2 ) ;
return;
}
V_5 = F_10 ( NULL , V_9 , V_10 , 0 , 1 , div ) ;
if ( F_9 ( V_5 ) ) {
F_5 ( L_4 , V_2 ) ;
return;
}
F_11 ( V_5 , NULL , V_9 ) ;
F_12 ( V_2 , V_11 , V_5 ) ;
}
