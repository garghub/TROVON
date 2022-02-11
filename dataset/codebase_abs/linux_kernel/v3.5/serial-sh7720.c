static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned short V_4 ;
if ( V_3 & V_5 ) {
if ( V_2 -> V_6 == 0xa4430000 ) {
V_4 = F_2 ( V_7 ) ;
F_3 ( ( V_4 & 0xfc03 ) , V_7 ) ;
} else if ( V_2 -> V_6 == 0xa4438000 ) {
V_4 = F_2 ( V_8 ) ;
F_3 ( ( V_4 & 0xfc03 ) , V_8 ) ;
}
} else {
if ( V_2 -> V_6 == 0xa4430000 ) {
V_4 = F_2 ( V_7 ) ;
F_3 ( ( V_4 & 0xffc3 ) , V_7 ) ;
} else if ( V_2 -> V_6 == 0xa4438000 ) {
V_4 = F_2 ( V_8 ) ;
F_3 ( ( V_4 & 0xffc3 ) , V_8 ) ;
}
}
}
