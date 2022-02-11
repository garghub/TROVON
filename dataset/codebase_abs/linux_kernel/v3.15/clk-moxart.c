void T_1 F_1 ( struct V_1 * V_2 )
{
static void T_2 * V_3 ;
struct V_4 * V_4 , * V_5 ;
unsigned int V_6 ;
const char * V_7 = V_2 -> V_7 ;
const char * V_8 ;
F_2 ( V_2 , L_1 , & V_7 ) ;
V_8 = F_3 ( V_2 , 0 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_5 ( L_2 , V_2 -> V_9 ) ;
return;
}
V_6 = F_6 ( V_3 + 0x30 ) >> 3 & 0x3f ;
F_7 ( V_3 ) ;
V_5 = F_8 ( V_2 , 0 ) ;
if ( F_9 ( V_5 ) ) {
F_5 ( L_3 , V_2 -> V_9 ) ;
return;
}
V_4 = F_10 ( NULL , V_7 , V_8 , 0 , V_6 , 1 ) ;
if ( F_9 ( V_4 ) ) {
F_5 ( L_4 , V_2 -> V_9 ) ;
return;
}
F_11 ( V_4 , NULL , V_7 ) ;
F_12 ( V_2 , V_10 , V_4 ) ;
}
void T_1 F_13 ( struct V_1 * V_2 )
{
static void T_2 * V_3 ;
struct V_4 * V_4 , * V_11 ;
unsigned int div , V_12 ;
unsigned int V_13 [] = { 2 , 3 , 4 , 6 , 8 } ;
const char * V_7 = V_2 -> V_7 ;
const char * V_8 ;
F_2 ( V_2 , L_1 , & V_7 ) ;
V_8 = F_3 ( V_2 , 0 ) ;
V_3 = F_4 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_5 ( L_2 , V_2 -> V_9 ) ;
return;
}
V_12 = F_6 ( V_3 + 0xc ) >> 4 & 0x7 ;
F_7 ( V_3 ) ;
if ( V_12 > 4 )
V_12 = 0 ;
div = V_13 [ V_12 ] * 2 ;
V_11 = F_8 ( V_2 , 0 ) ;
if ( F_9 ( V_11 ) ) {
F_5 ( L_3 , V_2 -> V_9 ) ;
return;
}
V_4 = F_10 ( NULL , V_7 , V_8 , 0 , 1 , div ) ;
if ( F_9 ( V_4 ) ) {
F_5 ( L_4 , V_2 -> V_9 ) ;
return;
}
F_11 ( V_4 , NULL , V_7 ) ;
F_12 ( V_2 , V_10 , V_4 ) ;
}
