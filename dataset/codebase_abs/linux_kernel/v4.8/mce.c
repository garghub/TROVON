static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_4 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
if ( ! ( V_5 -> V_9 & V_10 ) )
return V_11 ;
F_2 ( & V_12 ) ;
F_3 (acpi_desc, &acpi_descs, list) {
struct V_13 * V_14 = V_7 -> V_14 ;
int V_15 = 0 ;
F_2 ( & V_7 -> V_16 ) ;
F_3 (nfit_spa, &acpi_desc->spas, list) {
struct V_17 * V_18 = V_8 -> V_18 ;
if ( F_4 ( V_18 ) != V_19 )
continue;
if ( V_18 -> V_20 > V_5 -> V_21 )
continue;
if ( ( V_18 -> V_20 + V_18 -> V_22 - 1 ) < V_5 -> V_21 )
continue;
V_15 = 1 ;
F_5 ( V_14 , L_1 ,
V_23 , V_18 -> V_24 , V_18 -> V_20 ,
V_18 -> V_22 ) ;
break;
}
F_6 ( & V_7 -> V_16 ) ;
if ( V_15 )
F_7 ( V_7 ) ;
}
F_6 ( & V_12 ) ;
return V_11 ;
}
void F_8 ( void )
{
F_9 ( & V_25 ) ;
}
void F_10 ( void )
{
F_11 ( & V_25 ) ;
}
