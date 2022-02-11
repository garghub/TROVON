struct V_1 * F_1 ( void )
{
F_2 ( & V_2 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_4 , V_5 ) ;
if ( V_3 ) {
V_6 ++ ;
} else {
F_4 (KERN_ERR PREFIX
L_1 , ACPI_AC_CLASS) ;
}
F_5 ( & V_2 ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_7 )
{
F_2 ( & V_2 ) ;
if ( V_7 )
V_6 -- ;
if ( V_6 == 0 && V_7 && V_3 ) {
F_7 ( V_4 , V_5 ) ;
V_3 = NULL ;
}
F_5 ( & V_2 ) ;
}
struct V_1 * F_8 ( void )
{
F_2 ( & V_2 ) ;
if ( ! V_8 ) {
V_8 =
F_3 ( V_9 , V_5 ) ;
}
if ( V_8 ) {
V_10 ++ ;
} else {
F_4 (KERN_ERR PREFIX
L_1 , ACPI_BATTERY_CLASS) ;
}
F_5 ( & V_2 ) ;
return V_8 ;
}
void F_9 ( struct V_1 * V_11 )
{
F_2 ( & V_2 ) ;
if ( V_11 )
V_10 -- ;
if ( V_10 == 0 && V_11
&& V_8 ) {
F_7 ( V_9 , V_5 ) ;
V_8 = NULL ;
}
F_5 ( & V_2 ) ;
return;
}
