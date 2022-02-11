void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 , * V_4 ;
F_2 (node, next, &acpi_wakeup_device_list) {
struct V_5 * V_6 =
F_3 ( V_3 , struct V_5 , V_7 ) ;
if ( ! V_6 -> V_8 . V_9 . V_10
|| V_1 > ( V_11 ) V_6 -> V_8 . V_1
|| ! ( F_4 ( & V_6 -> V_6 )
|| V_6 -> V_8 . V_12 ) )
continue;
if ( F_4 ( & V_6 -> V_6 ) )
F_5 ( V_6 , V_1 ) ;
F_6 ( V_6 -> V_8 . V_13 , V_6 -> V_8 . V_14 ,
V_15 ) ;
}
}
void F_7 ( T_1 V_1 )
{
struct V_2 * V_3 , * V_4 ;
F_2 (node, next, &acpi_wakeup_device_list) {
struct V_5 * V_6 =
F_3 ( V_3 , struct V_5 , V_7 ) ;
if ( ! V_6 -> V_8 . V_9 . V_10
|| V_1 > ( V_11 ) V_6 -> V_8 . V_1
|| ! ( F_4 ( & V_6 -> V_6 )
|| V_6 -> V_8 . V_12 ) )
continue;
F_6 ( V_6 -> V_8 . V_13 , V_6 -> V_8 . V_14 ,
V_16 ) ;
if ( F_4 ( & V_6 -> V_6 ) )
F_8 ( V_6 ) ;
}
}
int T_2 F_9 ( void )
{
struct V_2 * V_3 , * V_4 ;
F_10 ( & V_17 ) ;
F_2 (node, next, &acpi_wakeup_device_list) {
struct V_5 * V_6 = F_3 ( V_3 ,
struct V_5 ,
V_7 ) ;
if ( F_11 ( & V_6 -> V_6 ) ) {
F_12 ( V_6 -> V_8 . V_13 ,
V_6 -> V_8 . V_14 ) ;
F_13 ( & V_6 -> V_6 , true ) ;
}
}
F_14 ( & V_17 ) ;
return 0 ;
}
